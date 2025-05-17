FROM python:3.10.7-slim

RUN apt-get update && apt-get install curl wget -y
RUN mkdir /app
COPY ./src/ /app
COPY ./flag /flag
RUN chmod 444 /flag
RUN pip3 install flask flask-cors pyyaml==5.3.0
WORKDIR /app

CMD ["python3", "-u", "app.py"]
