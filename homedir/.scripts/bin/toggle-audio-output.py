#!/usr/bin/env python

# No arquivo /etc/pulse/default.pa:
# -load-module module-stream-restore
# +load-module module-stream-restore restore_device=false

from os import remove
from os.path import isfile
from subprocess import run, PIPE

default_pa = "/etc/pulse/default.pa"
toggle_config='/tmp/.audio_output_toggle_HDMI'

if isfile(toggle_config):
    S = "1"
    remove(toggle_config)
else:
    S = "0"
    open(toggle_config, 'a').close()

p = run('pacmd list-sink-inputs | grep "^\s*index" | sed -e "s/[^0-9]//g"',
        shell=True, stdout=PIPE).stdout
sinks = str(p, 'utf-8').split()

run(["pacmd", "set-default-sink", S], stdout=PIPE)
[run(["pacmd", "move-sink-input", index, S], stdout=PIPE) for index in sinks]

p = run("cat " + default_pa + " | grep 'restore_device=false'",
    stdout=PIPE, shell=True).returncode
if p == 1:
    print("Please, edit \"%s\"" % default_pa)
