#!/bin/bash

sudo apt install -y cmake g++ libssl-dev libboost-dev
sudo apt install -y libboost-system-dev libboost-filesystem-dev
sudo apt install -y libmysqlcppconn-dev
sudo apt install -y libmysqlclient-dev
sudo apt install -y openapi-generator-cli

dpkg -L libmysqlclient-dev
dpkg -L libmysqlcppconn-dev

sudo npm install -g @openapitools/openapi-generator-cli

