#!/usr/bin/env bash

# ============================================================================ #
# Autor: Marcus Bruno - github.com/mrcsbrn                                     #
# Descrição: Instalação minima e completa para algo operacional                #
# ============================================================================ #

_aurmanager=trizen

if ! which $_aurmanager >/dev/null 2>&1; then
    echo "Installing AUR manager"
    bash ./install-aur-manager.sh
fi

inst() {
    $_aurmanager --noedit --noconfirm --needed -S "$@"
}

set -x

echo "Finding fastest Antergos mirrors"
if [ -f /etc/pacman.d/antergos-mirrorlist ]; then
    sudo cp /etc/pacman.d/antergos-mirrorlist /etc/pacman.d/antergos-mirrorlist.bup
    sudo rankmirrors -n 0 /etc/pacman.d/antergos-mirrorlist >/tmp/antergos-mirrorlist && sudo cp /tmp/antergos-mirrorlist /etc/pacman.d
fi

echo "Finding fastest Arch mirrors"
if ! which reflector >/dev/null 2>&1; then
    echo "Installing \"reflector\""
    inst reflector
fi
sudo reflector --verbose --latest 5 --sort rate --save /etc/pacman.d/mirrorlist

echo "Upgrading system"
$_aurmanager -Syu

# Instalando Xorg
sudo pacman -S xorg
inst xorg-init xcape xorg-xinit
echo "exec dwm" >~/.xinitrc

# Fontes
inst adobe-source-code-pro-fonts otf-font-awesome tamsyn-font ttf-dejavu ttf-ms-fonts
# Utilidades
inst firefox udiskie feh sxiv-git sxiv-rifle tmux-git rsync silver-searcher-git
inst ranger-git redshift redshift-gtk-git mupdf htop mpd ncmpcpp lyvi-git vim
inst keepassxc gnome-screenshot neofetch ncpamixer unclutter-xfixes-git
sudo mv /usr/share/sounds/freedesktop/stereo/camera-shutter.oga /usr/share/sounds/freedesktop/stereo/camera-shutter.oga.orig
inst dropbox network-manager-applet networkmanager
inst urlview mpv qt4 task-spooler
# Audio
inst pulseaudio pulseaudio-alsa alsa-lib alsa-plugins alsa-utils projectm-pulseaudio

# Construindo suckless
pp=$HOME/workspace/outros/dotfiles/data/suckless
cp -r $pp/dwm /tmp
cp -r $pp/dmenu /tmp
cp -r $pp/st /tmp
cp -r $pp/slstatus /tmp

at=$PWD
sudo mkdir /usr/X11R6
sudo ln -s /usr/lib/X11 /usr/X11R6/lib
sudo ln -s /usr/include/X11 /usr/X11R6/include
cd /tmp
cd dwm && sudo make install && cd ..
cd dmenu && sudo make install && cd ..
cd st && sudo make install && cd ..
cd slstatus && sudo make install && cd ..
cd $at

# Instalando clipmenu
inst clipnotify xsel xclip
cd /tmp
git clone https://github.com/cdown/clipmenu
sudo cp clipmenu/clipmenu /usr/bin
sudo cp clipmenu/clipmenud /usr/bin
cd $at

# Sincronizando dotfiles com dotdrop
inst python-pip
sudo pip install -r ./dotdrop/requirements.txt
./dotdrop.sh -V install

sudo rmmod pcspkr
echo "Done"
set +x
