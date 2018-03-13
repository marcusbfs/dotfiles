#!/usr/bin/env bash

usage(){
    t="    "
    echo "usage: $0 [flags] path_to_wallpaper"
    echo "options:"
    echo "$t-l, --light:  make a light theme"
    echo "$t-h, --help:   shows this message"
    exit 0;
}

[ -f ~/.cache/mpvbg.pid ] && kill $(cat ~/.cache/mpvbg.pid); rm ~/.cache/mpvbg.pid


[ $# -eq 0 ] && usage


while [ $# -gt 0 ]; do
    case "$1" in
        -l|--light) _light=true ;;
        -h|--help)  usage ;;
        *) path="$1"
    esac
    shift
done

[ ! -f "$path" ] && usage

# gera scheme com o pywal
wp_ext="$(basename $(file -b -i -L $path))"
case $wp_ext in
    "gif;"|"mp4;"|"webm;")
        dash ./mpvbg $path & ;;
    "png;"|"jpg;"|"jpeg;")
        feh --bg-fill --no-fehbg $path &;;
esac

if [ -n "$_light" ]; then
    wal -nli "$path"
else
    wal -ni "$path"
fi

sl_dir=$(realpath suckless)

cd $sl_dir"/st" && make clean && make -j4 && sudo make install && make clean
sed -i '/urg_/d' ~/.cache/wal/colors-wal-dwm.h
cd $sl_dir"/dwm" && make clean && make -j4 && sudo make install && make clean

