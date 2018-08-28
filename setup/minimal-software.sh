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

inst terminus-font-ll2-td1 proggyfonts ttf-dejavu
inst udiskie feh sxiv-git sxiv-rifle tmux-git rsync silver-searcher-git ranger-git
inst redshift-gtk-git mupdf ncdu htop mpd ncmpcpp lyvi-git mpc vim
inst keepassxc gnome-screenshot gnome-keyring neofetch ncpamixer unclutter-xfixes-git maim
inst mpv qt4 task-spooler transmission-cli transmission-remote-cli-git youtube-dl-git
inst pulseaudio pulseaudio-alsa alsa-lib alsa-plugins alsa-utils
inst xsel xclip
inst python-pip python-setuptools python-pyaml python-jinja python-docopt
inst quicksynergy
inst dtrx tar unzip cpio rpm-org binutils gzip bzip2 xz p7zip unrar cabextract unshield lha
inst i3lock-color scrot imagemagick
inst gst-libav gst-plugins-base gst-plugins-good gst-plugins-bad gst-plugins-ugly pdfjs qt5-webkit

sudo rmmod pcspkr
[ -f /usr/share/sounds/freedesktop/stereo/camera-shutter.oga ] && sudo mv /usr/share/sounds/freedesktop/stereo/camera-shutter.oga /usr/share/sounds/freedesktop/stereo/camera-shutter.oga.orig
sudo sed -i 's/^\(load-module\smodule-stream-restore\)$/\1 restore_device=false/' /etc/pulse/default.pa

set +x
