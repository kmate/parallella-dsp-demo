var chunkSize = 1024;
var bufferSize = 2 * 42 * 1024; // ~ 2 seconds at 44100Hz

var input;
var socket;
var recorder;
var buffer;
var bufferNext;

function startClicked() {
    var p = navigator.mediaDevices.getUserMedia({ audio: true });
    p.then(captureSuccess);
    p.catch(function(error) {
        console.error("Failed to initialize sound capture.")
        console.error(error.name);
    });
}

function captureSuccess(stream) {
    var context = new AudioContext();    
    input = context.createMediaStreamSource(stream);
    recorder = context.createScriptProcessor(chunkSize, 1, 1);
    bufferNext = bufferSize;
    input.connect(recorder);
    
    socket = new WebSocket("ws://localhost:8000/ws");
    socket.binaryType = "arraybuffer";
    socket.onopen = function(event) {
        recorder.onaudioprocess = function(event) {
            var inputBuffer = event.inputBuffer;
            var inputData = inputBuffer.getChannelData(0);
            if (socket) {
                socket.send(inputData);
            }
        };
    };
    socket.onerror = function(event) {
        console.error("Connection error.")
        console.error(event);
    };
    socket.onmessage = function(event) {
        if (bufferNext == bufferSize) {
            bufferNext = 0;
            buffer = context.createBuffer(1, bufferSize, context.sampleRate);
        }
        
        var received = new Float32Array(event.data);
        var target = buffer.getChannelData(0);
        for (var i = 0; i < chunkSize; i++) {
            target[bufferNext + i] = received[i];
        }
        bufferNext += chunkSize;
        
        if (bufferNext == bufferSize) {
            var output = context.createBufferSource();
            output.buffer = buffer;
            output.connect(context.destination);
            output.start();
        }
    };
}

function stopClicked() {
    if (recorder && input) {
        input.disconnect(recorder);
        input = recorder = null;
    }
    if (socket) {
        socket.close();
        socket = null;
    }
}

function attachListeners() {
    var btnStart = document.getElementById("start");
    var btnStop  = document.getElementById("stop");
    btnStart.onclick = startClicked;
    btnStop.onclick  = stopClicked;
}

window.onload = attachListeners;

