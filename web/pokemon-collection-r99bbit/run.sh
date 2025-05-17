#!/bin/bash

echo "Listen 8989" >> /etc/apache2/ports.conf

a2enmod php7.4
a2enmod cgi
service apache2 start
service apache2 restart


chmod -R 777 /var/www/html/uploads/
chmod -R 777 /var/www/html/cgi-bin/

cron -f
