#!/bin/bash

WHITE='\033[1;37m'
ORANGE='\033[0;33m'
END='\033[0m'

function ft_ip {
    MINIKUBE_IP="$(kubectl get node -o=custom-columns='DATA:status.addresses[0].address' | sed -n 2p)"
}

function ft_mysql_build {
    printf "${WHITE}Build mysql image: ${END}"
    sed -i -e "s/x.x.x.x/${MINIKUBE_IP}/g" ./srcs/mysql/srcs/wordpress.sql
    docker build -t mysql --build-arg minikube_ip=$KUBE_IP ./srcs/mysql > /dev/null 2>&1
    printf "%5s""${ORANGE}[BUILT]${END}\n"
}

function ft_influxdb_build {
    printf "${WHITE}Build influxdb image: ${END}"
    docker build -t influxdb ./srcs/influxdb > /dev/null 2>&1
    printf "%2s""${ORANGE}[BUILT]${END}\n"
}

function ft_nginx_build {
    printf "${WHITE}Build nginx image:  ${END}"
    docker build -t nginx ./srcs/nginx > /dev/null 2>&1
    printf "%4s""${ORANGE}[BUILT]${END}\n"
}

function ft_wordpress_build {
    printf "${WHITE}Build wordpress image: ${END}"
    docker build -t wordpress ./srcs/wordpress > /dev/null 2>&1
    printf "%1s""${ORANGE}[BUILT]${END}\n"
}

function ft_phpmyadmin_build {
    printf "${WHITE}Build phpmyadmin image: ${END}"
    docker build -t phpmyadmin ./srcs/phpmyadmin > /dev/null 2>&1
    printf "%s""${ORANGE}[BUILT]${END}\n"
}

function ft_ftps_build {
    printf "${WHITE}Build ftps image: ${END}"
    docker build -t ftps --build-arg minikube_ip=$KUBE_IP ./srcs/ftps > /dev/null 2>&1
    sudo apt-get install filezilla -y > /dev/null 2>&1
    printf "%6s""${ORANGE}[BUILT]${END}\n"
}

function ft_grafana_build {
    printf "${WHITE}Build grafana image: ${END}"
    docker build -t grafana ./srcs/grafana > /dev/null 2>&1
    printf "%3s""${ORANGE}[BUILT]${END}\n"
}
