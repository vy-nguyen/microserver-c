#!/bin/bash

apt_install() {
    sudo apt install -y cmake g++ libssl-dev libboost-dev meson
    sudo apt install -y libboost-system-dev libboost-filesystem-dev libboost-json-dev 
    sudo apt install -y libmysqlcppconn-dev
    sudo apt install -y libmysqlclient-dev
    sudo apt install -y openapi-generator-cli
    sudo apt install -y libmysqlclient-dev

    dpkg -L libmysqlclient-dev
    dpkg -L libmysqlcppconn-dev
}

yum_install() {
    sudo dnf install -y boost-devel openssl-devel mysql-devel
    sudo dnf install -y mysql-connector-cpp-devel java-11-openjdk
    wget https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/6.6.0/openapi-generator-cli-6.6.0.jar -O openapi-generator-cli.jar
    sudo dnf install -y nodejs npm
    sudo dnf install -y python3-pip
}

yum_install

sudo npm install -g @openapitools/openapi-generator-cli
sudo pip3 install PyJWT
sudo pip3 install mysql-connector-python
