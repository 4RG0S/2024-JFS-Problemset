FROM ubuntu:20.04

# 32bit
#RUN dpkg --add-architecture i386

ENV PORT=12370
ENV FILE_NAME='/home/simple_rop/prob'

RUN apt-get update

# test
#RUN apt-get install -y openssh-server gdb

# 32bit
#RUN apt-get install -y libc6:i386 libncurses5:i386 libstdc++6:i386

RUN apt-get install -y socat gcc

RUN useradd -d /home/simple_rop simple_rop -s /bin/bash
RUN mkdir /home/simple_rop

RUN chown -R simple_rop:simple_rop /home/simple_rop

COPY ./src/flag /flag
COPY ./src/prob.c /home/simple_rop/prob.c

RUN chown root:simple_rop /flag
RUN chmod 440 /flag

WORKDIR '/home/simple_rop'
RUN gcc -fno-stack-protector -no-pie prob.c -o prob -ldl
RUN chmod 755 /home/simple_rop /home/simple_rop/prob

WORKDIR '/'

CMD socat TCP-LISTEN:$PORT,reuseaddr,fork EXEC:"su simple_rop -c $FILE_NAME,,pty,raw,echo=0,stderr"