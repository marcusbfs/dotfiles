#!/bin/env bash

# No arquivo /etc/pulse/default.pa:
# -load-module module-stream-restore
# +load-module module-stream-restore restore_device=false

toggle_config=/tmp/.audio_output_toggle_HDMI

if [[ ! -e "$toggle_config" ]]; then
    # Muda pro audio hdmi
    pacmd set-default-sink 0

    for index in $(pacmd list-sink-inputs | grep "^\s*index" | sed -e "s/[^0-9]//g"); do
        pacmd move-sink-input $index 0
    done

    touch "$toggle_config"
else
    # Muda pro audio do headphone
    pacmd set-default-sink 1

    for index in $(pacmd list-sink-inputs | grep "^\s*index" | sed -e "s/[^0-9]//g"); do
        pacmd move-sink-input $index 1
    done

    rm "$toggle_config"
fi
