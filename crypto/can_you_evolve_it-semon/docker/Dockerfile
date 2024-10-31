FROM ubuntu:22.04

RUN apt-get -y update --fix-missing
RUN apt-get -y upgrade
RUN apt-get install -y build-essential
RUN apt-get -y install socat python3 python3-pip
RUN apt-get -y install net-tools
RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN chmod 1733 /tmp /var/tmp /dev/shm
# RUN pip3 install some_package_name

ADD . /home/ctf

WORKDIR /home/ctf
RUN chmod 440 flag.txt
RUN chmod 550 main

RUN chown -R root:ctf /home/ctf

USER ctf
CMD socat TCP-L:9999,reuseaddr,fork EXEC:"./main"
