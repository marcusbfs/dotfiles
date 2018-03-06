#!usr/bin/env bash

#This is the ffmpeg command that the screencast shortcut in i3 will run.

#Picks a file name for the output file based on availability:

if [ ! -d "$HOME/workspace/screencast_videos" ]; then
    mkdir -p -v "$HOME/workspace/screencast_videos"
fi

builtin cd "$HOME/workspace/screencast_videos"

while [[ -f ./screencast$n.mkv ]]; do
    n=$((n + 1))
done

filename="screencast$n.mkv"

#The actual ffmpeg command:

ffmpeg -y \
    -f x11grab \
    -s $(xdpyinfo | grep dimensions | awk '{print $2;}') \
    -i :0.0 \
    -thread_queue_size 1024 \
    -f alsa -ar 44100 -i default \
    -c:v libx264 -r 30 -c:a flac $filename
#-c:v ffvhuff -r 30 -c:a flac $filename
