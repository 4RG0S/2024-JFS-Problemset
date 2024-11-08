FROM ubuntu:24.04
ENV user guest
ENV port 31337

RUN apt-get -qq -y update
RUN apt-get -qq -y install socat build-essential libc6

RUN useradd -m $user

WORKDIR /home/$user

COPY ./binary_flag/ /home/$user/

RUN chown -R root /home/$user/
RUN chmod 651 /home/$user
RUN chgrp $user /home/$user/flag
RUN chmod 640 /home/$user/flag
RUN chgrp $user /home/$user/even_odd
RUN chmod 755 /home/$user/even_odd
RUN rm -rf /home/$user/.bashrc /home/$user/.profile /home/$user/.bash_logout

RUN ln -snf /usr/share/zoneinfo/Asia/Seoul /etc/localtime

CMD socat -T 10 TCP-LISTEN:$port,reuseaddr,fork EXEC:/home/$user/even_odd

USER $user
EXPOSE $port

