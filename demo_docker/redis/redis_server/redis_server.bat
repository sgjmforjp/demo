@echo OFF

echo WORK_DIR:%~dp0
cd %~dp0

docker-compose -f redis_compose_server.yml up -d
rem docker-compose -f redis_compose_server.yml down