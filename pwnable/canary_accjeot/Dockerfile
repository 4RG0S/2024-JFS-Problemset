FROM ubuntu:20.04

# 32bit
#RUN dpkg --add-architecture i386

ENV PORT=12370
ENV FILE_NAME='/home/canary/prob'

RUN apt-get update

# test
#RUN apt-get install -y openssh-server gdb

# 32bit
#RUN apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386

RUN apt-get install -y socat gcc

RUN useradd -d /home/canary canary -s /bin/bash
RUN mkdir /home/canary

RUN chown -R canary:canary /home/canary

COPY ./src/flag /flag
COPY ./src/prob.c /home/canary/prob.c

RUN chown root:canary /flag
RUN chmod 440 /flag

WORKDIR '/home/canary'
RUN gcc -fno-stack-protector -z execstack prob.c -o prob
RUN chmod 755 /home/canary /home/canary/prob

WORKDIR '/'

CMD socat TCP-LISTEN:$PORT,reuseaddr,fork EXEC:"su canary -c $FILE_NAME,,pty,raw,echo=0,stderr"