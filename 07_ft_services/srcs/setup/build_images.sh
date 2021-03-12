#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

source ./srcs/scripts/images_setup.sh

function ft_build_images {
    printf "\n${GREEN}[+] ${BLUE}Build images ${END}\n"
    ft_ip
    ft_mysql_build
    ft_influxdb_build
    ft_nginx_build
    ft_wordpress_build
    ft_phpmyadmin_build
    ft_ftps_build
    ft_grafana_build
    printf "${GREEN}[COMPLETE]${END}\n"
}
