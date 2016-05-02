rm -rf *.fifo
gcc -std=c99 -Icsrc csrc/mongoose.c csrc/server.c -o dsp-server
gcc -std=c99 -Icsrc csrc/processor.c -lm -o dsp-processor
./dsp-processor &
./dsp-server
rm -rf dsp-processor
rm -rf dsp-server
rm -rf *.fifo

