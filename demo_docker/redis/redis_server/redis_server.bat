@echo OFF

echo WORK_DIR:%~dp0
cd %~dp0

xcopy ..\config\*redis-server.conf .\deploy\server_1\config /YIF
xcopy ..\config\*redis-server.conf .\deploy\server_2\config /YIF
xcopy ..\config\*redis-server.conf .\deploy\server_3\config /YIF
xcopy ..\config\*redis-sentinel.conf .\deploy\sentinel_1\config /YIF
xcopy ..\config\*redis-sentinel.conf .\deploy\sentinel_2\config /YIF
xcopy ..\config\*redis-sentinel.conf .\deploy\sentinel_3\config /YIF

docker-compose -f redis_compose_server.yml up -d
rem docker-compose -f redis_compose_server.yml down
