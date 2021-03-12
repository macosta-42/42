FROM  alpine:3

RUN mkdir -p /run/nginx
RUN apk update
RUN apk add --no-cache --upgrade bash
RUN apk add nginx
RUN apk add openrc --no-cache
RUN apk add php7-fpm php7 php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-xmlreader  php7-xmlwriter\
 php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc \
 php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-session php7-mbstring php7-openssl libxml2 php7-gd php7-pear
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN mkdir start
RUN mkdir certif
COPY srcs/index.html ./www/index.html
COPY srcs/start.sh ./start
COPY srcs/nginx.conf ./etc/nginx/nginx.conf
COPY srcs/localhost.pem ./certif
COPY srcs/localhost-key.pem ./certif
COPY srcs/default.conf ./etc/nginx/conf.d/default.conf
COPY ./phpmyadmin/ ./www/phpmyadmin/
COPY srcs/telegraf.conf ./etc/
COPY srcs/config.inc.php ./www/phpmyadmin
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN rc-update add nginx default
ENTRYPOINT ["/bin/bash", "/start/start.sh"]
