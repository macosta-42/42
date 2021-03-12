#!/bin/bash

WHITE='\033[1;37m'
ORANGE='\033[0;33m'
END='\033[0m'

function ft_ip {
    MINIKUBE_IP="$(kubectl get node -o=custom-columns='DATA:status.addresses[0].address' | sed -n 2p)"
}

function ft_mysql_deploy {
    printf "\n${WHITE}Create persistent volume for mysql: ${END}\n"
    kubectl create -f ./srcs/mysql/mysql.yaml
    sed -i -e "s/${MINIKUBE_IP}/x.x.x.x/g" ./srcs/mysql/srcs/wordpress.sql
    printf "${ORANGE}[CREATED]${END}\n"
}

function ft_influxdb_deploy {
    printf "\n${WHITE}Create persistent volume for influxdb: ${END}\n"
    kubectl create -f ./srcs/influxdb/influxdb.yaml
    printf "${ORANGE}[CREATED]${END}\n"
}

function ft_nginx_deploy {
    printf "\n${WHITE}nginx: ${END}\n"
    kubectl create -f ./srcs/nginx/nginx.yaml
    printf "${ORANGE}[STARTED]${END}\n"
}

function ft_wordpress_deploy {
    printf "\n${WHITE}wordpress: ${END}\n"
    kubectl create -f ./srcs/wordpress/wordpress.yaml
    printf "${ORANGE}[STARTED]${END}\n"
}

function ft_phpmyadmin_deploy {
    printf "\n${WHITE}phpmyadmin: ${END}\n"
    kubectl create -f ./srcs/phpmyadmin/phpmyadmin.yaml
    printf "${ORANGE}[STARTED]${END}\n"
}

function ft_ftps_deploy {
    printf "\n${WHITE}ftps: ${END}\n"
    kubectl create -f ./srcs/ftps/ftps.yaml
    printf "${ORANGE}[STARTED]${END}\n"
}

function ft_grafana_deploy {
    printf "\n${WHITE}grafana: ${END}\n"
    kubectl create -f ./srcs/grafana/grafana.yaml
    printf "${ORANGE}[STARTED]${END}\n"
}

function ft_create_volumes {
    ft_mysql_deploy
    ft_influxdb_deploy
    printf "\n${WHITE}Initalize database: ${END}\n"
    sleep 30
    printf "${ORANGE}[COMPLETE]${END}\n"
}
