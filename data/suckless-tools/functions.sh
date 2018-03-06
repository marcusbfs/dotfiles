_blink_window() {
    val=0.4
    slp=0.1
    num=2
    for i in $(seq 1 $num); do
        transset-df -a --dec $val && sleep $slp && transset-df -a --inc $val
        sleep $slp
    done
}

_xmanager() {
    xdflts=$(realpath ~/.Xdefaults)
    xrsrcs=$(realpath ~/.Xresources)
    if [ -f $xdflts ]; then
        xrdb -load $xdflts
        echo "Xdefaults loaded"
    fi
    if [ -f $xrsrcs ]; then
        xrdb -merge $xrsrcs
        echo "Xresources merged"
    fi
}

_polybar_launcher() {
    # Terminate already running bar instances
    killall -q polybar
    # Wait until the processes have been shut down
    while pgrep -x polybar >/dev/null; do sleep 1; done
    # Launch bar1 and bar2
    polybar Bar -c $HOME/.config/i3/polybar/config -q &
}

_compton_launcher() {
    killall -q compton
    while pgrep -x compton >/dev/null; do sleep 1; done
    sleep 0.2 && compton --config $HOME/.config/i3/compton.conf &
}

_toggle_audio_output() {
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
}

_simple_lock() {
    if which betterlockscreen >/dev/null 2>&1; then
        betterlockscreen -l dim
    else
        lock_img=~/.config/i3/nlock.png
        imgpath=/tmp/i3screenshot.png
        scrot --silent $imgpath
        convert $imgpath -blur 0x3 $imgpath
        if [[ -f $lock_img ]]; then
            convert $imgpath $lock_img \
                -gravity center -composite -matte \
                $imgpath
        fi
        i3lock -i $imgpath && rm $imgpath
    fi
}

_screenshooter() {
    if which gnome-screenshot >/dev/null 2>&1; then
        # para desabilitar o som, renomeio o arquivo
        # /usr/share/sounds/freedesktop/stereo/camera-shutter.oga
        gnome-screenshot --interactive
    elif which gscreenshot >/dev/null 2>&1; then
        gscreenshot
    else
        echo "install gnome-screenshot or gscreenshot"
        return 1
    fi
}

_play_ytmpv() {
    # preciso estar com o link copiado
    if which xsel >/dev/null 2>&1; then
        selectedtext=$(xsel -o -b)
    elif which xclip >/dev/null 2>&1; then
        selectedtext=$(xclip -o -selection clipboard)
    else
        echo "install xsel or xclip"
        return 1
    fi
    tsp mpv --ontop --no-border --volume=50 --force-window --autofit=600x380 --geometry=-15-15 "$selectedtext"
}

"$@"
