#!/usr/bin/env bash

link="$1"

c=$(echo -e "720p\n1080p\nloop\naudio" |
    dmenu -i -p "mpv")

mpv_common="--quiet --autofit=1280x720 --volume=60 --geometry=50%:15%"

case "$c" in
"720p")
    mpv $mpv_common \
        --ytdl-format="bestvideo[height<=?720][fps<=?30]+bestaudio/best" \
        "$link" &>/dev/null
    ;;
"1080p")
    mpv $mpv_common \
        --ytdl-format="bestvideo[height<=?1080][fps<=?30]+bestaudio/best" \
        "$link" &>/dev/null
    ;;
"loop")
    mpv $mpv_common --loop \
        --ytdl-format="bestvideo[height<=?720][fps<=?30]+bestaudio/best" \
        "$link" &>/dev/null
    ;;
"audio")
    mpv $mpv_common --no-video --force-window \
        --ytdl-format="bestvideo[height<=?720][fps<=?30]+bestaudio/best" \
        "$link" &>/dev/null
    ;;
esac
