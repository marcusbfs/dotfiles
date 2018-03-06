#!/usr/bin/env bash

ip=$(netstat -rn | awk 'FNR == 3 {print $2}')
$BROWSER $ip
sudo vim /etc/hosts -c ":%s/^/#/"
