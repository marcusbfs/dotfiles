#!/usr/bin/env python

from shutil import which
from subprocess import run
from os.path import expanduser, isfile

def main():

    lock_exec = which('betterlockscreen')
    if lock_exec:
        run([lock_exec, "-l", "dim"])
        return 0

    else:
        lock_exec = which('i3lock')
        lock_img=expanduser("~/.config/i3/nlock.png")
        imgpath=expanduser("/tmp/i3screenshot.png")
        run(["scrot", "--silent", imgpath])
        run(["convert", imgpath, "-blur", "0x3", imgpath])

        if isfile(lock_img):
            run(["convert", imgpath, lock_img, "-gravity", "center",
                "-composite", "-matte", imgpath])

        run([lock_exec, "-i", imgpath])
        run(["rm", imgpath])


if __name__ == "__main__":
    main()
