#!/bin/sh
sudo docker run --name web-pokemon-strength -dit -p 5002:5000 --restart unless-stopped web-pokemon-strength