#!/usr/bin/env python

import subprocess


def main():

    device_id = 'SynPS/2 Synaptics TouchPad'  # obtido por xinput --list (pacote: xorg-xinput)

    p = subprocess.run(
        "xinput list-props '" + device_id + "' | grep 'Device Enabled.*0'",
        shell=True,
        universal_newlines=True,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)

    if p.returncode == 0:  # disabled
        xinput_cmd = ['xinput', 'enable', device_id]

    else:
        xinput_cmd = ['xinput', 'disable', device_id]

    subprocess.Popen(xinput_cmd)


if __name__ == '__main__':
    main()
