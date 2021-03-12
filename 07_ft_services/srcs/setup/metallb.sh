#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

source ./srcs/scripts/metallb_setup.sh

function ft_metallb {
    printf "\n${GREEN}[+] ${BLUE}Start MetalLB LoadBalancer ${END}\n"
    kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl diff -f - -n kube-system > /dev/null 2>&1
    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
    kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
    minikube addons enable metallb
    ft_get_ip
    ft_set_yaml
    printf "${GREEN}[COMPLETE]${END}\n"
}