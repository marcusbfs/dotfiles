#!/usr/bin/env bash

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
img=$DIR/pink.jpg
sound_notification=/usr/share/sounds/freedesktop/stereo/alarm-clock-elapsed.oga

short_interval_time="5m"
long_interval_time="15m"
pomodoro_time="25m"

no-point() { echo $(basename $1); }
#no-point() { echo $(echo $1 | sed 's/\.\///g'); }

usage() {
    echo "$(no-point $0) -p: pomodoro ($pomodoro_time)"
    echo "$(no-point $0) -i: short interval ($short_interval_time)"
    echo "$(no-point $0) -l: long interval ($long_interval_time)"
    exit 1
}

[ $# -lt 1 ] && usage

case "$1" in
-p)
    start_phrase="starting pomodoro"
    timer=$pomodoro_time
    end_phrase="pomodoro finished"
    ;;
-i)
    start_phrase="starting short interval"
    timer=$short_interval_time
    end_phrase="short interval finished"
    ;;
-l)
    start_phrase="starting long interval"
    timer=$long_interval_time
    end_phrase="long interval finished"
    ;;
-h)
    usage
    ;;
*)
    usage
    ;;
esac

echo "$start_phrase"
date
sleep "$timer" && (feh -F "$img" &) && (paplay --volume=40000 $sound_notification &)
date
echo "$end_phrase"" finished"
