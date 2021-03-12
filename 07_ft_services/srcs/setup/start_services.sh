#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

source ./srcs/scripts/services_setup.sh

function ft_start_services {
    printf "\n${GREEN}[+] ${BLUE}Deploy services ${END}\n"
    ft_ip
    ft_create_volumes
    ft_nginx_deploy
    ft_wordpress_deploy
    ft_phpmyadmin_deploy
    ft_ftps_deploy
    ft_grafana_deploy
    printf "${GREEN}[COMPLETE]${END}\n"
}
