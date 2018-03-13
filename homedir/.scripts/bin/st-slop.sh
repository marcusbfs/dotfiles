#!/usr/bin/env bash

read -r X Y W H < <(slop -f "%x %y %w %h" -b 1 -t 0 -q)
# Width and Height in px need to be converted to columns/rows
# To get these magic values, make a fullscreen st, and divide your screen width by ${tput cols}, height by ${tput lines}
# Example, in monitor of 1920x1080:
# H = echo "1920 / $(tput cols)" | bc

(( W /= 8 ))
(( H /= 16 ))
g=${W}x${H}+${X}+${Y}

#echo "st -c st-slop -g $g"
st -c st-float -g $g
