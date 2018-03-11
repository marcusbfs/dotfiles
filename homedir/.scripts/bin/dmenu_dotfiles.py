#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import print_function, absolute_import, division

import csv
import os
import shutil
import subprocess


def main():

    term = 'st'
    configrc = '~/workspace/outros/dotfiles/homedir/.scripts/configs2sync'
    cfg_files = get_files_dict(configrc)
    cfg_files_key = list(cfg_files.keys())

    sel_key = dmenu_list(cfg_files_key, args='-l 10', prompt='files: ')
    sel_file = get_fullpath(cfg_files[sel_key])

    editor = "$EDITOR"
    editor = get_fullpath(editor)

    cmd = [term, '-e', editor, sel_file]

    subprocess.Popen(cmd)


def dmenu_list(arr, prompt=None, args=None):
    dmenu = 'dmenu'
    if not shutil.which(dmenu):
        print('dmenu not found')
        raise

    dmenu_cmd = [dmenu, '-i']

    if prompt:
        dmenu_cmd.append('-p')
        dmenu_cmd.append(prompt)

    if args:
        for a in args.split():
            dmenu_cmd.append(a)

    proc = subprocess.Popen(
        dmenu_cmd,
        universal_newlines=True,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE)

    with proc.stdin:
        for a in arr:
            proc.stdin.write(a)
            proc.stdin.write('\n')

    if proc.wait() == 0:
        return proc.stdout.read().rstrip('\n')


def get_files_dict(config_file):

    config_file_fullpath = get_fullpath(config_file)

    if not os.path.isfile(config_file_fullpath):
        print('Config file does not exists')
        return 1

    dct = {}
    with open(config_file_fullpath) as cfg:
        for line in csv.reader(cfg, delimiter=' '):
            dct[line[0]] = line[1]

    return dct


def get_fullpath(path):
    return os.path.expandvars(os.path.expanduser(path))


if __name__ == '__main__':
    main()
