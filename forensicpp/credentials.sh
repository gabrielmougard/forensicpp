#!/bin/bash

echo -n $(docker exec $(docker ps | grep "forensick-db" | awk '{print $1}') cat /run/secrets/mariadb_forensick_forensick_password)
