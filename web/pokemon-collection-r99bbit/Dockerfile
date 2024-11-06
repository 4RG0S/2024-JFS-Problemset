FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install -y tzdata python3
RUN apt-get install -y apache2
RUN apt-get install -y php7.4 libapache2-mod-php7.4
RUN apt-get install -y gcc
RUN apt-get install -y cron

RUN rm /var/www/html/*
RUN rm /etc/apache2/sites-enabled/000-default.conf
RUN ln -fs /dev/null /var/log/apache2/access.log
RUN ln -fs /dev/null /var/log/apache2/error.log

ADD src/bash_history /root/.bash_history
ADD src/settings/sites.conf /etc/apache2/sites-enabled/
ADD run.sh /tmp/run.sh
ADD src/html /var/www/html

ADD ./flag.c /flag.c
RUN gcc -o /flag /flag.c
RUN rm /flag.c
RUN chmod 000 /flag
RUN chmod +x /flag

ADD src/settings/crontab.txt /etc/cron.d/prob-clean
RUN chmod 0644 /etc/cron.d/prob-clean
RUN crontab /etc/cron.d/prob-clean

RUN chmod -R 777 /root
RUN chmod +x /tmp/run.sh

CMD ["/bin/bash", "/tmp/run.sh"]