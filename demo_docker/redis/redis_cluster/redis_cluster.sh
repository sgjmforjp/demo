#!bin/bash

SHELL_FOLDER=$(dirname $(readlink -f "$0"))
cd $SHELL_FOLDER

mkdir -p ./deploy/node_1/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_1/config
mkdir -p ./deploy/node_2/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_2/config
mkdir -p ./deploy/node_3/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_3/config
mkdir -p ./deploy/node_4/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_4/config
mkdir -p ./deploy/node_5/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_5/config
mkdir -p ./deploy/node_6/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_6/config
mkdir -p ./deploy/node_7/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_7/config
mkdir -p ./deploy/node_8/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_8/config
mkdir -p ./deploy/node_9/config && cp -rfp ../config/redis-cluster.conf ./deploy/node_9/config

docker-compose -f redis_compose_cluster.yml up -d
# docker-compose -f redis_compose_server.yml down
