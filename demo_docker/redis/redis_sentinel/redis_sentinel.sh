#!bin/bash

SHELL_FOLDER=$(dirname $(readlink -f "$0"))
cd $SHELL_FOLDER

docker-compose -f redis_compose_sentinel.yml up -d
# docker-compose -f redis_compose_sentinel.yml down