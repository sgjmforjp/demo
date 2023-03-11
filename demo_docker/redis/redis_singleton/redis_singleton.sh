#!bin/bash

SHELL_FOLDER=$(dirname $(readlink -f "$0"))
cd $SHELL_FOLDER

cp -rfp ../config/*redis-server.conf ./deploy/config

docker-compose -f redis_compose_singleton.yml up -d
# docker-compose -f redis_compose_singleton.yml down
