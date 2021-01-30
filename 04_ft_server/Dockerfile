FROM debian:buster

MAINTAINER Matthieu Costa <macosta@student.42.fr>

COPY srcs/nginx.conf ./root/
COPY srcs/config.inc.php ./root/
COPY srcs/wp-config.php ./root/
COPY srcs/start.sh ./

RUN chmod 755 ./start.sh
CMD bash ./start.sh

EXPOSE 80 443

ENV INDEX_AUTO on
#systemctl stop nginx
#docker build -t ft_server .
#docker run -it -p 80:80 -p 443:443 ft_server
