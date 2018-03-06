#!/usr/bin/env bash

template="template.sh"
scheme="$1"

set -a
. "$scheme"
set +a

tempfile=$(mktemp)
trap 'rm -f $tempfile'

(
  echo 'cat <<END_OF_TEXT'
    cat "$template" | grep -v 'vi: ft='
      echo 'END_OF_TEXT'

) > $tempfile
. $tempfile
