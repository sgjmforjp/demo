@ECHO OFF

ECHO WORK_DIR:%~dp0
CD %~dp0

docker-compose -f env_compose.yml build --no-cache
