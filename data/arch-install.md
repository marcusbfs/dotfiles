loadkeys br-abnt2

# muda o mirrorlist:
pacman -Syy reflector
reflector -c Brazil -f 12 -l 12 --verbose --save /etc/pacman.d/mirrorlist

# ver discos dispon�veis
lsblk

# Agora deve ficar atento ao tipo de boot do sistema: uefi/efi ou bios/legacy
# se a pasta /sys/firmware/efi existir, o sistema � uefi/efi. Os procedimentos
# de parti��o do disco devem ser feitos de acordo com o tipo de boot

# Para um sistema encriptado utilizando o sistema de arquivos LVM, dever� ter a(s)
# parti��es necess�rias do boot + uma outra (que ser� a do LVM)

### ex. bios/legacy ###
cfdisk
-> dos
-> /dev/sda1 - 512M - bootable -  Type Linux
-> /dev/sda2 - o resto - - Type Linux
-> write: yes

# formatando a parti��o de boot
mkfs.ext2 /dev/sda1

## parte de encripta��o
# formata a parti��o para o tipo luks
cryptsetup -v -y luksFormat /dev/sda2
-> YES
-> digitar uma senha FORTE

## abrir a parti��o encripatada
cryptsetup luksOpen /dev/sda2 archlv
ls /dev/mapper/archlv  # verifica se deu tudo certinho

## cria os devidos grupos e parti��es LVM
pvcreate /dev/mapper/archlv
vgcreate archvg /dev/mapper/archlv

lvcreate -L 5G archvg -n swap  # cria swap (ajustar para o tamanho desejado)
lvcreate -L 30G archvg -n root  # cria root de 30G
lvcreate -l 100%FREE archvg -n home  # cria home com o restante do disco
# se n�o for desejado fazer home separado de root, basta apenas colocar 100%FREE no root

# formatando parti��es LVM
mkfs.ext4 /dev/mapper/archvg-root
mkfs.ext4 /dev/mapper/archvg-home
mkswap /dev/mapper/archvg-swap

# montando as parti��es
mount /dev/mapper/archvg-root /mnt
mkdir /mnt/home
mount /dev/mapper/archvg-home /mnt/home
mkdir /mnt/boot
mount /dev/sda1 /mnt/boot
swapon /dev/mapper/archvg-swap
lsblk  # para verificar se esta tudo OK

### Instala��o do sistema base. O �nico pacote realmente necess�rio � o "base", mas eu gosto de j�
# adicionar alguns outros que eu uso
pacstrap /mnt base base-devel git zsh vim sudo

# gera fstab e verifica se n�o possui erros
genfstab -U /mnt >> /mnt/etc/fstab
cat /mnt/etc/fstab

# muda root
arch-chroot /mnt

# Arruma a regi�o e o hor�rio do hardware
ln -sf /usr/share/zoneinfo/America/Sao_Paulo /etc/localtime
hwclock --systohc --utc

vim /etc/locale.gen  # e DEScomenta pt_BR.UTF-8 UTF-8
locale-gen
echo LANG=pt_BR.UTF-8 > /etc/locale.conf
echo KEYMAP=br-abnt2 > /etc/vconsole.conf

# arrumar hostname
echo "escolher hostname" > /etc/hostname
-> vim /etc/hosts
-- 127.0.0.1	localhost.localdomain	localhost
-- ::1		localhost.localdomain	localhost
-- 127.0.1.1	meuhostname.localdomain	meuhostname

# configurar internet
systemctl enable dhcpcd

# configurar boot
-> vim /etc/mkinitcpio.conf
-- HOOKS="......keyboard encrypt lvm2 filesystems..."

mkinitcpio -p linux

# muda a senha do root
passwd
# adiciona usu�rio
useradd -m -g users -G wheel -s /bin/zsh NOME_DO_USUARIO
passwd NOME_DO_USUARIO
visudo
%wheel ALL=(ALL) ALL  # descomente essa linha (tire o # do come�o)

## instalar grub e configurar
pacman -S grub
--> vim /etc/default/grub
-- GRUB_CMD_LINUX_DEFAULT="cryptdevice=/dev/sda2:archlv quiet"
# se for bios/legacy:
grub-install --target=i386-pc /dev/sda
# se n�o for, veja https://wiki.archlinux.org/index.php/GRUB

grub-mkconfig -o /boot/grub/grub.cfg  # pode dar uns WARNING's, mas t� tudo OK

# Instala��o terminou. Saia do chroot, desmonte as parti��es, desligue e retire a iso
exit
umount -R /mnt
swapoff -a
reboot

### INSTALA��O TERMINA AQUI ###
# logue como usu�rio comum
# instalando Xorg
sudo pacman -S xorg-server xorg-xinit xorg-xsetroot
# instalar drive de v�deo. Primeiro, saiba qual seu drive:
lspci | grep -e VGA -e 3D
pacman -Ss xf86-video  # instale o adequado dessa lista

# deped�ncias suckless
sudo pacman -S libx11 libxinerama libxft freetype2 libxext xorg-fonts-misc ncurses

# teclado
sudo pacman -S xcape

# audio
sudo pacman -S pulseaudio pulseaudio-alsa ffmpeg alsa-utils pavucontrol