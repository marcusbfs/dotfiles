#!/usr/bin/env python

import os
import shutil
import subprocess


def main():

    lock_exec = shutil.which('betterlockscreen')
    if lock_exec:
        subprocess.run([lock_exec, "-l", "dim"])
        return 0

    else:
        lock_exec = shutil.which('i3lock')
        lock_img = os.path.expanduser("~/.config/i3/nlock.png")
        imgpath = os.path.expanduser("/tmp/i3screenshot.png")
        subprocess.run(["scrot", "--silent", imgpath])
        subprocess.run(["convert", imgpath, "-blur", "0x3", imgpath])

        if os.path.isfile(lock_img):
            subprocess.run([
                "convert", imgpath, lock_img, "-gravity", "center",
                "-composite", "-matte", imgpath
            ])

        subprocess.run([lock_exec, "-i", imgpath])
        subprocess.run(["rm", imgpath])


if __name__ == "__main__":
    main()
