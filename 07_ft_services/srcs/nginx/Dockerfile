FROM  alpine:3

USER root
RUN mkdir -p /run/nginx
RUN apk update
RUN apk add --no-cache --upgrade bash
RUN apk add nginx
RUN apk add openrc --no-cache
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN mkdir start
RUN mkdir certif
COPY srcs/index.html ./www/index.html
COPY srcs/static ./www/static
COPY srcs/start_nginx.sh ./start
COPY srcs/nginx.conf ./etc/nginx/nginx.conf
COPY srcs/localhost.pem ./certif
COPY srcs/localhost-key.pem ./certif
COPY srcs/default.conf ./etc/nginx/conf.d/default.conf
COPY srcs/telegraf.conf ./etc/
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN rc-update add nginx default
EXPOSE 80 443
ENTRYPOINT ["/bin/bash", "/start/start_nginx.sh"]
