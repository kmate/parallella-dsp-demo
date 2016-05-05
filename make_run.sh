rm -rf *.fifo
rm -rf gen/*
cabal build
dist/build/parallella-dsp-demo/parallella-dsp-demo
gcc -std=c99 -Iinclude csrc/mongoose.c csrc/server.c -o dsp-server
gcc -std=c99 -Iinclude -I../imperative-edsl/include ../imperative-edsl/csrc/chan.c gen/processor.c -lpthread -lm -o dsp-processor
./dsp-processor &
# valgrind --tool=callgrind ./dsp-processor &
# valgrind --tool=drd --show-stack-usage=yes ./dsp-processor 2>stack_usage.txt &
./dsp-server
sleep 1
# grep 'finished and used' stack_usage.txt | sort
# rm -rf stack_usage.txt
rm -rf dsp-processor
rm -rf dsp-server
rm -rf *.fifo
