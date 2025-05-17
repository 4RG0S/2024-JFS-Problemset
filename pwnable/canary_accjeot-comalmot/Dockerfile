FROM ubuntu:20.04

# 32bit
#RUN dpkg --add-architecture i386

ENV PORT=12370
ENV FILE_NAME='/home/simple_canary/prob'

RUN apt-get update

# test
#RUN apt-get install -y openssh-server gdb

# 32bit
#RUN apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386

RUN apt-get install -y socat gcc

RUN useradd -d /home/simple_canary simple_canary -s /bin/bash
RUN mkdir /home/simple_canary

RUN chown -R simple_canary:simple_canary /home/simple_canary

COPY ./src/flag /flag
COPY ./src/prob.c /home/simple_canary/prob.c

RUN chown root:simple_canary /flag
RUN chmod 440 /flag

WORKDIR '/home/simple_canary'
RUN gcc -z execstack prob.c -o prob
RUN chmod 755 /home/simple_canary /home/simple_canary/prob

WORKDIR '/'

CMD socat TCP-LISTEN:$PORT,reuseaddr,fork EXEC:"su simple_canary -c $FILE_NAME,,pty,raw,echo=0,stderr"