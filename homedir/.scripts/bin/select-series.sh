#!/usr/bin/env bash

mpath=/run/media/mrcsbrn/mrcshd/Videos/Series
_ls=/usr/bin/ls
dmenu_args="-i $@"

d_files() {
    $_ls $1 | sort -f | dmenu -p series $dmenu_args
}

_get_movie_name() {
    movie=$1
    childs=$(find $movie/* -type d | wc -l)

    if [ $childs -eq 0 ]; then
        mname=$($_ls $movie/*.{mp4,mkv,avi} 2>/dev/null)
    else
        dm=$(d_files $movie)
        [[ $dm ]] || exit 2
        movie=$movie/$dm
        mname=$(_get_movie_name $movie)
    fi
    echo $movie
    echo $mname
}

dm=$(d_files $mpath)
[[ $dm ]] || exit 1

movie=$mpath/$dm

tmp=$(_get_movie_name $movie)
i=1
tmpfile=/tmp/.select-series
rm -f $tmpfile
for f in $tmp; do
    if [[ $i -eq 1 ]]; then
        movie=$f
        i=2
    else
        echo $(basename $f) >>$tmpfile
    fi
done

dm=$(cat $tmpfile | dmenu -p episodes $dmenu_args)
[[ $dm ]] || exit 3

mname=$movie/$dm
$PLAYER $mname >/dev/null 2>&1 &
