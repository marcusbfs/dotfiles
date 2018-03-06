#!/usr/bin/env bash

mpath=/run/media/mrcsbrn/mrcshd/Videos/Movies
_ls=/usr/bin/ls
dmenu_args="-i $@"

d_files() {
    $_ls $1 | sort -f | dmenu -p movies $dmenu_args
}

dm=$(d_files $mpath)
[[ $dm ]] || exit 1

movie=$mpath/$dm

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
    echo $mname
}

mname=$(_get_movie_name $movie)
$PLAYER $mname >/dev/null 2>&1 &
