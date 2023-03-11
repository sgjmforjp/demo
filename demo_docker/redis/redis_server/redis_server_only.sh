#!bin/bash

SHELL_FOLDER=$(dirname $(readlink -f "$0"))
cd $SHELL_FOLDER

cp -rfp ../config/*redis-server.conf ./deploy/server_1/config
cp -rfp ../config/*redis-server.conf ./deploy/server_2/config
cp -rfp ../config/*redis-server.conf ./deploy/server_3/config

docker-compose -f redis_compose_server_only.yml up -d
# docker-compose -f redis_compose_server.yml down
