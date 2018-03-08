#!/usr/bin/env python

import os
import shutil
import subprocess

vid_ext = ['.mp4', '.avi', '.mkv', '.flv', '.wmv', '.mov']


def main():

    mpath = "/run/media/mrcsbrn/mrcshd/Videos/Series"
    cwd = mpath

    while has_dir_inside(cwd):
        ctmp = dmenu_select_dir(cwd, '-p series -l 30')
        if not ctmp:
            return 1
        cwd = os.path.join(cwd, ctmp)

    video = dmenu_select_video(cwd, '-p episodes -l 30')
    video = os.path.join(cwd, video)

    # mpv_cmd = os.path.expandvars("command $PLAYER")
    mpv_cmd = 'mpv'

    subprocess.Popen(
        mpv_cmd + ' ' + video,
        shell=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)
    return 0


def has_dir_inside(path):
    # checa se há diretório com vídeos dentro
    for f in os.listdir(path):
        if os.path.isdir(os.path.join(path, f)):
            for ff in os.listdir(os.path.join(path, f)):
                if os.path.splitext(ff)[-1] in vid_ext:
                    return True
    return False


def dmenu_select_dir(path, args):
    movies = [
        f for f in os.listdir(path) if os.path.isdir(os.path.join(path, f))
    ]
    if len(movies) == 1:
        return movies[0]

    tmp = ''
    for m in movies:
        tmp += m + '\n'

    _s = subprocess.run(
        'echo "' + tmp.rstrip() + '" | sort -f | dmenu -i ' + args,
        shell=True,
        stdout=subprocess.PIPE).stdout
    return str(_s, 'utf-8').rstrip()


def dmenu_select_video(path, args):

    movies = [
        f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))
        if os.path.splitext(os.path.join(path, f))[-1] in vid_ext
    ]
    if len(movies) == 1:
        return movies

    tmp = ''
    for m in movies:
        tmp += m + '\n'

    _s = subprocess.run(
        'echo "' + tmp.rstrip() + '" | sort -f | dmenu -i ' + args,
        shell=True,
        stdout=subprocess.PIPE).stdout
    return str(_s, 'utf-8').rstrip()


if __name__ == '__main__':
    main()
