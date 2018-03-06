# -*- coding: utf-8 -*-

import os
import csv

zsh = ""
rgr = ""

dir_path = os.path.dirname(os.path.realpath(__file__))

with open(os.path.join(dir_path, "zshrc.base")) as zs:
    zsh += zs.read()

with open(os.path.join(dir_path, "rc.conf.base")) as r:
    rgr += r.read()

with open(os.path.join(dir_path, "folders2sync")) as fold:
    for line in csv.reader(fold, delimiter=' '):
        zsh += ("alias " + line[0] + "=\"builtin cd " + line[1] + " && ls -a\"\n")
        rgr += ("map g" + line[0] + " cd " + line[1] + "\n")

with open(os.path.join(dir_path, "configs2sync")) as conf:
    for line in csv.reader(conf, delimiter=' '):
        zsh += ("alias " + line[0] + "=\"$EDITOR " + line[1] + "\"\n")
        rgr += ("map " + line[0] + " shell vim " + line[1] + "\n")

homepath = os.path.expanduser("~")

with open(os.path.join(homepath, ".zshrc"), "w") as outzsh:
    outzsh.write(zsh)
with open(os.path.join(homepath, ".config/ranger/rc.conf"), "w") as outrgr:
    outrgr.write(rgr)
