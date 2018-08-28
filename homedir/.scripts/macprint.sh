#!/usr/bin/env bash

f=/tmp/printscrotfoo.png

maim -m 1 -s -f png "$f"

xclip -selection clipboard -target "image/png" "$f"

rm "$f"
