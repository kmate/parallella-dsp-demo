#!/bin/bash

set -e

rm -rf *.fifo
rm -rf *.elf
rm -rf *.srec
gcc -std=c99 -Iinclude csrc/mongoose.c csrc/server.c -o dsp-server

ESDK=${EPIPHANY_HOME}
ELIBS=${ESDK}/tools/host/lib
EINCS=${ESDK}/tools/host/include
ELDF=${ESDK}/bsps/current/internal.ldf

SCRIPT=$(readlink -f "$0")
EXEPATH=$(dirname "$SCRIPT")
cd $EXEPATH

CROSS_PREFIX=
case $(uname -p) in
	arm*)
		# Use native arm compiler (no cross prefix)
		CROSS_PREFIX=
		;;
	   *)
		# Use cross compiler
		CROSS_PREFIX="arm-linux-gnueabihf-"
		;;
esac

# Build HOST side application
${CROSS_PREFIX}gcc -std=gnu99 -D_BSD_SOURCE csrc/feldspar-parallella.c gen/host.c -o dsp-processor -Iinclude -I ${EINCS} -L ${ELIBS} -le-hal -le-loader -lm -lpthread

cd gen
for f in core*.c
do
    ELF=../${f%.*}.elf
    SREC=../${f%.*}.srec

    # Build DEVICE side programs
    e-gcc -std=gnu99 -ffast-math -fsingle-precision-constant -I../include -T ${ELDF} ../csrc/feldspar-parallella.c $f -o ${ELF} -le-lib -lm -O2
    # Convert ebinaries to SREC files
    e-objcopy --srec-forceS3 --output-target srec ${ELF} ${SREC}
done
cd ..

./dsp-processor &
./dsp-server
sleep 1
#rm -rf dsp-processor
#rm -rf dsp-server

#rm -rf *.fifo
#rm -rf *.elf
#rm -rf *.srec

