#!/usr/bin/env bash

# ============================================================================ #
# Autor: Marcus Bruno - github.com/mrcsbrn                                     #
# Descrição: Instala o gerenciador de pacotes "pacaur"                         #
# ============================================================================ #

_cw=$PWD
cd /tmp
git clone https://aur.archlinux.org/trizen-git.git
cd trizen-git
makepkg -si
cd $_cw

#mkdir -p /tmp/pacaur_install
#pushd /tmp/pacaur_install > /dev/null

#sudo pacman -S binutils make gcc fakeroot --noconfirm --needed
#sudo pacman -S expac yajl git --noconfirm --needed

#if [ ! -n "$(pacman -Qs cower)" ]; then
#curl -o PKGBUILD https://aur.archlinux.org/cgit/aur.git/plain/PKGBUILD?h=cower
#makepkg PKGBUILD --skippgpcheck --install --needed --noconfirm
#fi

#if [ ! -n "$(pacman -Qs pacaur)" ]; then
#curl -o PKGBUILD https://aur.archlinux.org/cgit/aur.git/plain/PKGBUILD?h=pacaur
#makepkg PKGBUILD --install --needed --noconfirm
#fi

#popd > /dev/null
#rm -r /tmp/pacaur_install
