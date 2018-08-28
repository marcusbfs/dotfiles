#!/usr/bin/env python

import os
import subprocess
import shutil


def main():

    _aurmanager = shutil.which('trizen')

    if not _aurmanager:
        print("Installing AUR manager")
        subprocess.run(["bash", "./install-aur-manager.sh"])

    def inst(pkg):
        print("installing \"%s\"" % pkg)
        cmd = [_aurmanager, "--noedit", "--noconfirm", "--needed", "-S"]
        for p in pkg.split():
            cmd.append(p)
        subprocess.run(cmd, stdout=None, stderr=subprocess.STDOUT)

    # Instalando pacotes
    inst('terminus-font-ll2-td1 proggyfonts ttf-dejavu')
    inst(
        'udiskie feh sxiv-git sxiv-rifle tmux-git rsync silver-searcher-git ranger-git'
    )
    inst('redshift-gtk-git mupdf ncdu htop mpd ncmpcpp lyvi-git mpc vim')
    inst(
        'keepassxc gnome-screenshot gnome-keyring neofetch ncpamixer unclutter-xfixes-git maim'
    )
    inst(
        'mpv qt4 task-spooler transmission-cli transmission-remote-cli-git youtube-dl-git'
    )
    inst('pulseaudio pulseaudio-alsa alsa-lib alsa-plugins alsa-utils')
    inst('xsel xclip')
    inst(
        'python-pip python-setuptools python-pyaml python-jinja python-docopt')
    inst('quicksynergy')
    inst(
        'dtrx tar unzip cpio rpm-org binutils gzip bzip2 xz p7zip unrar cabextract unshield lha'
    )
    inst('i3lock-color scrot imagemagick')
    inst(
        'gst-libav gst-plugins-base gst-plugins-good gst-plugins-bad gst-plugins-ugly pdfjs qt5-webkit'
    )

    # Outros
    subprocess.run(
        ["sudo", "rmmod", "pcspkr"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)

    camera_shutter_oga = '/usr/share/sounds/freedesktop/stereo/camera-shutter.oga'
    if os.path.isfile(camera_shutter_oga):
        subprocess.run([
            "sudo", "mv",
            "/usr/share/sounds/freedesktop/stereo/camera-shutter.oga",
            "/usr/share/sounds/freedesktop/stereo/camera-shutter.oga.orig"
        ])

    subprocess.run(
        "sudo sed -i 's/^\(load-module\smodule-stream-restore\)$/load-module module-stream-restore restore_device=false/' /etc/pulse/default.pa",
        shell=True)


if __name__ == '__main__':
    main()
