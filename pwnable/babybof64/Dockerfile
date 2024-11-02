FROM ubuntu:20.04

# 32bit
#RUN dpkg --add-architecture i386

ENV PORT=12370
ENV FILE_NAME='/home/nomitigation/prob'

RUN apt-get update

# test
#RUN apt-get install -y openssh-server gdb

# 32bit
#RUN apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386

RUN apt-get install -y socat gcc

RUN useradd -d /home/nomitigation nomitigation -s /bin/bash
RUN mkdir /home/nomitigation

RUN chown -R nomitigation:nomitigation /home/nomitigation

COPY ./prob/flag /flag
COPY ./prob/prob.c /home/nomitigation/prob.c

RUN chown root:nomitigation /flag
RUN chmod 440 /flag

WORKDIR '/home/nomitigation'
RUN gcc -fno-stack-protector -z execstack prob.c -o prob
RUN chmod 755 /home/nomitigation /home/nomitigation/prob

WORKDIR '/'

CMD socat TCP-LISTEN:$PORT,reuseaddr,fork EXEC:"su nomitigation -c $FILE_NAME,,pty,raw,echo=0,stderr"