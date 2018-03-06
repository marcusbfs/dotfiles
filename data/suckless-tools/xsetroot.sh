#!/usr/bin/env bash

if which slstatus >/dev/null 2>&1; then
    slstatus
else
    while true; do
        freehd="HD: $(df -h | grep -w '/' | awk '{printf $4}') "
        freemem=$(free -m | grep '^Mem' | awk '{printf "Memory used: %iMB", $3}' )
        date=$(date "+%a %b %d %Rh")
        sep=" "
        cpu="cpu: $(grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {printf "%2.2f%", usage}')"
        xsetroot -name "$cpu$sep$freemem$sep$freehd$sep$date$sep"
        sleep 5
    done
fi
