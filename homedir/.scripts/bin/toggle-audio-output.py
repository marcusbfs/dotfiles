#!/usr/bin/env python

# No arquivo /etc/pulse/default.pa:
# -load-module module-stream-restore
# +load-module module-stream-restore restore_device=false

import os
import subprocess

default_pa = "/etc/pulse/default.pa"
toggle_config = '/tmp/.audio_output_toggle_HDMI'

if os.path.isfile(toggle_config):
    S = "1"
    os.remove(toggle_config)
else:
    S = "0"
    open(toggle_config, 'a').close()

p = subprocess.run(
    'pacmd list-sink-inputs | grep "^\s*index" | sed -e "s/[^0-9]//g"',
    shell=True,
    stdout=subprocess.PIPE).stdout

sinks = str(p, 'utf-8').split()

subprocess.run(["pacmd", "set-default-sink", S], stdout=subprocess.PIPE)

[
    subprocess.run(
        ["pacmd", "move-sink-input",
         index.rstrip(), S],
        stdout=subprocess.PIPE) for index in sinks
]

p = subprocess.run(
    "cat " + default_pa + " | grep 'restore_device=false'",
    stdout=subprocess.PIPE,
    shell=True).returncode
if p == 1:
    print("Please, edit \"%s\"" % default_pa)
