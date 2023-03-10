@echo OFF

echo WORK_DIR:%~dp0
cd %~dp0

docker-compose -f mysql_compose.yml up -d
rem docker-compose -f deploy_compose.yml down