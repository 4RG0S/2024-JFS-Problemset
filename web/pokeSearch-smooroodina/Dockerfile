FROM php:8.3.0-apache

# RUN sed -i 's/stretch/buster/g' /etc/apt/sources.list

WORKDIR /var/www/html

COPY ./src/ /var/www/html/
COPY ./flag /flag

# RUN apt-get update

EXPOSE 80