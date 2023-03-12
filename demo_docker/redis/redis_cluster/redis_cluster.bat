@echo OFF

echo WORK_DIR:%~dp0
cd %~dp0

xcopy ../config/*redis-cluster.conf ./deploy/node_1/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_2/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_3/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_4/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_5/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_6/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_7/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_8/config /YIF
xcopy ../config/*redis-cluster.conf ./deploy/node_9/config /YIF

docker-compose -f redis_compose_cluster.yml up -d
rem docker-compose -f redis_compose_server.yml down
