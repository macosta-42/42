#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

function ft_version_checker {
CORRECT_VERSION="v1.20.0"
USER_VERSION=$(kubectl version --client | cut -d ' ' -f 5 | cut -d '"' -f 2)
if [ ${USER_VERSION} != ${CORRECT_VERSION} ]; then
	curl -LO https://storage.googleapis.com/kubernetes-release/release/v1.20.0/bin/linux/amd64/kubectl
	chmod +x ./kubectl
	sudo mv ./kubectl /usr/local/bin/kubectl
fi
}

function ft_start_minikube {
    printf "\n${GREEN}[+] ${BLUE}Start Minikube ${END}\n"
    ft_version_checker
    minikube start --vm-driver=docker
    printf "${GREEN}[COMPLETE]${END}\n"
}

function ft_set_env {
    printf "\n${GREEN}[+] ${BLUE}Set env ${END}\n"
    eval $(minikube docker-env)
    printf "${GREEN}[COMPLETE]${END}\n"
}

function ft_addons {
    printf "\n${GREEN}[+] ${BLUE}Enable addons for Dashboard ${END}\\n"
    minikube addons enable metrics-server
    minikube addons enable dashboard
    printf "${GREEN}[COMPLETE]${END}\n"
}

function ft_dashboard {
    printf "\n${GREEN}[+] ${BLUE}Launch Dashboard ${END}\n"
    minikube dashboard & > /dev/null 2>&1
    sleep 15
    printf "${GREEN}[COMPLETE]${END}\n"
    sleep 15
}
