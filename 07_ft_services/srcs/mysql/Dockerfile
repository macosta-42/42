FROM  alpine:3

USER root
RUN apk update
RUN apk add --no-cache --upgrade bash
RUN apk add mysql mysql-client
RUN apk add openrc
RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/v3.13/community
run mkdir start
COPY srcs/start.sh ./start
COPY srcs/my.cnf ./etc/
COPY srcs/start.sql ./start/
COPY srcs/db_wordpress.sql ./start/
COPY srcs/wordpress.sql ./start/
COPY srcs/phpmyadmin.sql ./start/
COPY srcs/mariadb-server.cnf ./etc/my.cnf.d/
COPY srcs/telegraf.conf ./etc/
EXPOSE 3306
ENTRYPOINT ["/bin/bash", "/start/start.sh"]
