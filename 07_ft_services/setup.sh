#!/bin/bash

BLUE='\033[1;34m'
GREEN='\033[1;32m'
END='\033[0m'

source ./srcs/setup/banner.sh
source ./srcs/setup/sudo.sh
source ./srcs/setup/clean.sh
source ./srcs/setup/minikube.sh
source ./srcs/setup/metallb.sh
source ./srcs/setup/build_images.sh
source ./srcs/setup/start_services.sh

clear
ft_banner
ft_sudo
ft_clean
ft_start_minikube
ft_set_env
ft_addons
ft_metallb
ft_build_images
ft_start_services
ft_dashboard
