#!/bin/bash
#UPDATE & INSTALL DEPENDENCIES
apt-get update
apt-get upgrade -y
apt-get install -y nginx
apt-get install -y openssl
apt-get install -y mariadb-server
apt-get install -y php-{fpm,mysql,common,cli,mbstring,common,json,opcache,readline}
apt-get install -y wget
apt-get clean

#SSL SETUP
touch ~/.rnd
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=FR/ST=75/L=Paris/O=42/CN=macosta' -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

#NGINX SETUP
cp /root/nginx.conf /etc/nginx/sites-available/localhost
ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled
rm /var/www/html/*.html

#MYSQL DATABASE SETUP
service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

#WORDPRESS SETUP
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
rm -rf latest.tar.gz
chmod 755 -R wordpress
mv wordpress/ /var/www/html/wordpress/
mv /root/wp-config.php /var/www/html/wordpress/

#PHPMYADMIN SETUP
mkdir /var/www/html/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz
tar -xvzf phpMyAdmin-4.9.5-all-languages.tar.gz --strip-components 1 -C /var/www/html/phpmyadmin
rm -rf phpMyAdmin-4.9.5-all-languages.tar.gz
mv /root/config.inc.php /var/www/html/phpmyadmin/

#NGINX USERS
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*

#SERVICE START
service mysql restart
service php7.3-fpm start
service nginx restart
/bin/bash
