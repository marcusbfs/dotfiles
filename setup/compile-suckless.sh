#!/usr/bin/env bash

suckless=~/workspace/outros/dotfiles/data/suckless

tdir=/tmp/sltmp
mkdir -p "$tdir"
cd "$tdir"

cp -r "$suckless"/st .
cp -r "$suckless"/dwm .
cp -r "$suckless"/slstatus .
cp -r "$suckless"/dmenu .

cc() {
    cd "$1" && make clean && make -j3 && sudo make install
    cd ..
}

cc "st"
cc "dwm"
cc "slstatus"
cc "dmenu"
