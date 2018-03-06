# Path
[ -d "$HOME/.local/bin" ] && PATH="$HOME/.local/bin:$PATH"
[ -d "$HOME/.scripts/bin" ] && PATH="$HOME/.scripts/bin:$PATH"

if [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
    exec startx
    #read -q "REPLY?start Xorg? "
    #case "$REPLY" in
        #y|Y ) exec startx;;
        #n|N ) echo "\nno";;
        #* ) echo "\ninvalid";;
    #esac
fi
