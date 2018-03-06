#!/usr/bin/env bash

# ============================================================================ #
# Autor: Marcus Bruno - github.com/mrcsbrn                                     #
# Descrição: Gerencia meus pacotes e dotfiles                                  #
# ============================================================================ #

# Variáveis
pacaur_flag=0
lt_flag=0
pc_flag=0
_aurmanager=trizen

# Cria pastas que eu mais utlizo
mkdir -p -v $HOME/workspace/outros
mkdir -p -v $HOME/Imagens/Wallpapers
mkdir -p -v $HOME/Downloads
mkdir -p -v $HOME/Música

while test $# -gt 0; do
    case "$1" in
    --pacaur) pacaur_flag=1
        ;;
    -lt) lt_flag=1
        ;;
    -pc) pc_flag=1
        ;;
    --*) echo "bad option $1"
        ;;
    *) echo "argument $1"
        ;;
    esac
    shift
done

osn=""

if [[ -f /etc/os-release ]]; then
    osn=$(cat /etc/os-release | awk -F'=' '/^NAME/ {print $2}' | sed 's/\"//g')
fi

if [[ $osn == "Ubuntu" ]]; then
    echo Ubuntu
    sudo apt-get update -y
    sudo apt-get upgrade -y
else
    echo "Arch"
    if ! which $_aurmanager >/dev/null 2>&1; then
        echo "Installing AUR manager"
        bash ./install-aur-manager.sh
    fi
    $_aurmanager -Syu
fi

if [[ -f ./packages.txt ]]; then

    echo "Installing packages"
    echo "\"packages.txt\" has $(cat packages.txt | sed '/^\s*$/d' | wc -l) packages"

    for f in $(cat ./packages.txt | sed '/^\s*$/d'); do
        if [[ $osn == "Ubuntu" ]]; then
            sudo apt-get install -f -y $f 2>/dev/null
        else
            $_aurmanager --noedit --noconfirm --needed -S $f
        fi
    done

    if [[ ! -f $HOME/.vim/autoload/plug.vim ]]; then
        echo "Installing vim-plug"
        curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
    fi

fi

# Usando stow para sincronizar dotfiles

if [[ "$pc_flag" == "1" ]]; then
    #stow -v -t  "$HOME" homedir
    ./dotdrop.sh -V install -p mrcspc
elif [[ "$lt_flag" == "1" ]]; then
    #stow -v -t  "$HOME" lthomedir
    ./dotdrop.sh -V install -p laptop
fi

exit
