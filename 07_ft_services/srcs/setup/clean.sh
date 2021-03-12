#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

function ft_clean {
    printf "\n${GREEN}[+] ${BLUE}Delete unwanted process ${END}\n"
    minikube delete
    NGINX_SERVICE="$(systemctl is-active nginx)"
    if [[ $NGINX_SERVICE == "active" ]]; then
        sudo systemctl stop nginx.service
    fi
    printf "${GREEN}[COMPLETE]${END}\n"
}