#!/bin/bash
chmod 777 /www/phpmyadmin/
openrc
touch /run/openrc/softlevel
service nginx start
rc-service php-fpm7 start
rc-service telegraf start
tail -f /dev/null
