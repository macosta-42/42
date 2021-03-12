#!/bin/bash

WHITE='\033[1;37m'
ORANGE='\033[0;33m'
END='\033[0m'

function ft_get_ip {
    printf "\n${WHITE}Minikube IP address : ${END}"
    MINIKUBE_IP="$(kubectl get node -o=custom-columns='DATA:status.addresses[0].address' | sed -n 2p)"
    printf "${ORANGE}${MINIKUBE_IP}${END}\n"
}

function ft_set_yaml {
    printf "${WHITE}Using Minikube IP for Metallb config${END}\n"
    sed -i -e "s/x.x.x.x/${MINIKUBE_IP}/g" ./srcs/scripts/metallb.yaml
    kubectl apply -f ./srcs/scripts/metallb.yaml
    sed -i -e "s/${MINIKUBE_IP}/x.x.x.x/g" ./srcs/scripts/metallb.yaml
}
