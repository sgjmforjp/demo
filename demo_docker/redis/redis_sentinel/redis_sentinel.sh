#!bin/bash

SHELL_FOLDER=$(dirname $(readlink -f "$0"))
cd $SHELL_FOLDER

cp -rfp ../config/*redis-sentinel.conf ./deploy/sentinel_1/config
cp -rfp ../config/*redis-sentinel.conf ./deploy/sentinel_2/config
cp -rfp ../config/*redis-sentinel.conf ./deploy/sentinel_3/config

docker-compose -f redis_compose_sentinel.yml up -d
# docker-compose -f redis_compose_sentinel.yml down