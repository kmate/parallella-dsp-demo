var input;
var recorder;
var socket;

function startClicked() {
    var p = navigator.mediaDevices.getUserMedia({ audio: true });
    p.then(captureSuccess);
    p.catch(function(error) {
        console.error("Failed to initialize sound captiure.")
        console.error(error.name);
    });
}

function captureSuccess(stream) {
    var context = new AudioContext();
    var bufferSize = 1024;
    
    socket = new WebSocket("ws://localhost:8000/ws");
    input = context.createMediaStreamSource(stream);
    recorder = context.createScriptProcessor(bufferSize, 1, 1);
    input.connect(recorder);
    
    socket.binaryType = "arraybuffer";
    socket.onopen = function(ev) {
        console.log(ev);
        recorder.onaudioprocess = function(event) {
            var inputBuffer = event.inputBuffer;
            var inputData = inputBuffer.getChannelData(0);
            console.log(inputData);
            if (socket) {
                socket.send(inputData);
            }
        };
    };
    socket.onerror = function(ev) { console.log(ev); };
    socket.onclose = function(ev) { console.log(ev); };
    socket.onmessage = function(ev) { console.log(ev); };

    
    /*
    var volume = context.createGain();
    var audioInput = context.createMediaStreamSource(e);
    audioInput.connect(volume);
    
    console.log([audioContext, context, sampleRate,volume,audioInput]);

    var bufferSize = 2048;
    var scriptNode = audioCtx.createScriptProcessor(4096, 1, 1);
    
    recorder.onaudioprocess = function(e) {
        console.log ('recording');
        var left = e.inputBuffer.getChannelData (0);
        var right = e.inputBuffer.getChannelData (1);
        // we clone the samples
        leftchannel.push (new Float32Array (left));
        rightchannel.push (new Float32Array (right));
        recordingLength += bufferSize;
    }
    volume.connect(recorder);
    recorder.connect(context.destination); 
    */
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

