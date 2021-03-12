#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

if [ "$#" -ne 1 ]; then
	printf "\n${GREEN}[-] ${BLUE}Usage: ./image_rebuild.sh [service_name] ${END}\n"
	exit 1
else
  if [ "$1" = "mysql" ] || [ "$1" = "influxdb" ] ||  [ "$1" = "nginx" ] || [ "$1" = "ftps" ] || [ "$1" = "wordpress" ] || [ "$1" = "phpmyadmin" ] || [ "$1" = "grafana" ]; then
	  eval $(minikube docker-env)
	  if [ "$1" = "ftps" ] || [ "$1" = "mysql" ]; then
		MINIKUBE_IP="$(kubectl get node -o=custom-columns='DATA:status.addresses[0].address' | sed -n 2p)"	    
		BUILD_ARG="--build-arg minikube_ip=$MINIKUBE_IP"
	  else
	    BUILD_ARG=""
	  fi
	  docker image rm -f $1
	  docker build -t $1 $BUILD_ARG ../../$1
	  printf "\n${GREEN}[*] ${BLUE}Image rebuilt${END}\n"
	else
	  printf "\n${GREEN}[!] ${BLUE}Can't find the service${END}\n"
	  exit 1
	fi
fi

exit 0
