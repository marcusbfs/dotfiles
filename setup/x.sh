#!/usr/bin/env bash

# ============================================================================ #
# Autor: Marcus Bruno - github.com/mrcsbrn                                     #
# Descrição: Instala o Xorg de maneira automática                              #
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

if [ -f /etc/pacman.d/antergos-mirrorlist ]; then
    echo "Finding fastest Antergos mirrors"
    sudo cp /etc/pacman.d/antergos-mirrorlist /etc/pacman.d/antergos-mirrorlist.bup
    sudo rankmirrors -n 0 /etc/pacman.d/antergos-mirrorlist >/tmp/antergos-mirrorlist && sudo cp /tmp/antergos-mirrorlist /etc/pacman.d
fi

echo "Finding fastest Arch mirrors"
if ! which reflector >/dev/null 2>&1; then
    echo "Installing \"reflector\""
    inst reflector
fi
sudo reflector --verbose --latest 5 --sort rate --save /etc/pacman.d/mirrorlist

echo "Upgrading system"
$_aurmanager -Syu

echo "Installing Xorg base"
sudo pacman -S xorg
inst xorg-init xorg-apps xterm

echo "Installing LightDM"
inst lightdm lightdm-webkit2-greeter
echo "Enabling LightDM"
systemctl enable lightdm.service
echo "Enabling NetworkManager"
systemctl enable NetworkManager.service

echo "Done"
echo "Reboot the system"
set +x
