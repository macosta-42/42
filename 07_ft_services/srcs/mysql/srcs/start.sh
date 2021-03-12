#!/bin/bash
openrc
touch /run/openrc/softlevel
/etc/init.d/mariadb setup
/etc/init.d/mariadb start
mkdir /www/phpmyadmin/tmp
chmod 777 /www/phpmyadmin/
mysql -u root < start/start.sql
mysql -u root < start/db_wordpress.sql
mysql -u root < start/wordpress.sql
mysql -u root < start/phpmyadmin.sql
/etc/init.d/mariadb restart
rc-service telegraf start
tail -f /dev/null
