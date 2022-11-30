#!/bin/bash

echo $(docker exec $(docker ps | grep "forensick-db" | awk '{print $1}') cat /run/secrets/mariadb_forensick_forensick_password)
