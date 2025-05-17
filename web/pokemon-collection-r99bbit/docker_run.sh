#!/bin/sh
sudo docker run --name web-pokemon-collection -d --restart unless-stopped -p 5001:80 -p 9153:9153 -p 8989:8989 web-pokemon-collection