#!/bin/bash
docker build -t pwn-even-odd .
docker run --rm -d -p 6001:31337 --name pwn-even-odd pwn-even-odd