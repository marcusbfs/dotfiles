#!/usr/bin/env bash

# ============================================================================ #
# Autor: Marcus Bruno - github.com/mrcsbrn                                     #
# Descrição: Instala outros programas mais pesados                             #
# ============================================================================ #

_aurmanager=trizen

if ! which $_aurmanager >/dev/null 2>&1; then
    echo "Installing AUR manager"
    bash ./install-aur-manager.sh
fi

inst() {
    $_aurmanager --noedit --noconfirm --needed -S "$@"
}

set -x

inst dropbox
inst wine
inst jdk
inst libreoffice-fresh
inst texlive-most

sudo rmmod pcspkr
echo "Done"
set +x
