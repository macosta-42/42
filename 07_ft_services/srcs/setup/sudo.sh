#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

function ft_sudo {
    printf "\n${GREEN}[+] ${BLUE}Get SUDO ${END}\n"
    sudo chmod 777 /var/run/docker.sock
    printf "${GREEN}[COMPLETE]${END}\n"
}