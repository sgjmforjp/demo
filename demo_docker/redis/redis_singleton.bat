@echo OFF

echo WORK_DIR:%~dp0
cd %~dp0

docker-compose -f redis_compose_singleton.yml up -d
rem docker-compose -f redis_compose_singleton.yml down