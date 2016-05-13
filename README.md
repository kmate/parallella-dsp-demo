# parallella-dsp-demo
Demo application for DSP on Parallella using RAW-Feldspar and Zeldspar

## Instructions

### Preparation

    git clone git@github.com:emilaxelsson/imperative-edsl
    git clone git@github.com:emilaxelsson/raw-feldspar
    git clone git@github.com:koengit/zeldspar
    git clone git@github.com:kmate/raw-feldspar-mcs
    git clone git@github.com:kmate/parallella-dsp-demo
    cd parallella-dsp-demo
    cabal sandbox init
    cabal sandbox add-source ../imperative-edsl
    cabal sandbox add-source ../raw-feldspar
    cabal sandbox add-source ../zeldspar
    cabal sandbox add-source ../raw-feldspar-mcs
    cabal install --constraint="language-c-quote -full-haskell-antiquotes"

### Running the server

    ./make_run.sh

Start a browser and go to http://localhost:8000/. Press "Start streaming" and talk to your microphone :)
Only tested with Firefox 46 on Linux Mint. There is no guarantee that it works with any other browsers, as the Web Audio API is only a draft now.
