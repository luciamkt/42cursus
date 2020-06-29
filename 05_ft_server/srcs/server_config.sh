#!/bin/bash

# create web directory
mkdir /var/www/localhost

# configure nginx
cp /etc/nginx/sites-available/default /etc/nginx/sites-available/default.old
mv /root/nginx.conf /etc/nginx/sites-available/default
mv /root/info.php /var/www/localhost/

# create SSL certificate
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout /etc/ssl/private/localhost.key \
-out /etc/ssl/certs/localhost.crt \
-subj "/C=BR/ST=Sao Paulo/L=Sao Paulo/O=42SP/CN=localhost"

# move to /root/ dir
cd /root

# download and install phpMyAdmin
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz
tar xvf phpMyAdmin-5.0.2-english.tar.gz
rm -rf phpMyAdmin-5.0.2-english.tar.gz
mv phpMyAdmin-5.0.2-english/ /var/www/localhost/phpmyadmin
mv /root/config.inc.php /var/www/localhost/phpmyadmin/config.inc.php
# set www-data — the Linux user profile that web servers use by default for normal operations in Ubuntu and Debian systems — as the owner of this directory
chown -R www-data:www-data /var/www/localhost/phpmyadmin

# create a user that has access to all databases
/etc/init.d/mysql start
mysql -e "CREATE USER 'ltakahas'@'localhost' IDENTIFIED BY 'asdf';"
mysql -e "GRANT ALL PRIVILEGES ON *.* TO 'ltakahas'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"

# create a database for wordpress
mysql -e "CREATE DATABASE wordpress"
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY '1234';"
mysql -e "FLUSH PRIVILEGES;"

# download and install Wordpress
wget https://wordpress.org/wordpress-5.4.1.tar.gz
tar -xzvf wordpress-5.4.1.tar.gz
rm -rf wordpress-5.4.1.tar.gz
mv wordpress /var/www/localhost/wordpress
mv /root/wp-config.php /var/www/localhost/wordpress/

# delete server_config file
rm -rf server_config.sh