#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

if [ "$#" -ne 1 ]; then
	printf "\n${GREEN}[-] ${BLUE}Usage: ./service_restart.sh [service_name] ${END}\n"
	exit 1
else
	if [ "$1" = "mysql" ] || [ "$1" = "influxdb" ] ||  [ "$1" = "nginx" ] || [ "$1" = "ftps" ] || [ "$1" = "wordpress" ] || [ "$1" = "phpmyadmin" ] || [ "$1" = "grafana" ]; then
	  eval $(minikube docker-env)
    ./service_del.sh $1
    kubectl create -f ../../$1/$1.yaml
	printf "\n${GREEN}[*] ${BLUE}Service restarted${END}\n"
	else
	  printf "\n${GREEN}[!] ${BLUE}Can't find the service${END}\n"
	  exit 1
	fi
fi	

exit 0
