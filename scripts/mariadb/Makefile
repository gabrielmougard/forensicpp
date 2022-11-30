# Copyright 2022 gab
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

##################################### VARIABLES #################################


#Get the current directory of this Makefile as it may be included in other Makefiles
#http://stackoverflow.com/questions/18136918/how-to-get-current-directory-of-your-makefile
MARIADB_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MARIADB_DIR := $(abspath $(patsubst %/,%,$(dir $(MARIADB_PATH))))

#Get the path to the top most Makefile, or wherever this command was invoked from
TOP_PATH := $(shell pwd)

#These could already be set in the env or when this Makefile 
#is included in the devtools/Makefile
MARIADB_TAG_NAME ?= mariadb-forensick:latest
MARIADB_SERVER_CONTAINER_NAME ?= forensick_mariadb_server
MARIADB_PORT ?= 3306
MARIADB_DUMP_FILE ?= ${TOP_PATH}/forensickk.dump.2022_10_27.sql.gz # TODO : update this value
MARIADB_USER ?= forensick
MARIADB_PASSWORD_FILE ?= /run/secrets/mariadb_forensick_forensick_password
MARIADB_ROOT_PASSWORD_FILE ?= /run/secrets/mariadb_forensick_root_password
MARIADB_DATABASE   ?= forensick

#MariaDB Server command line options
MARIADB_SERVER_OPTS = --name=${MARIADB_SERVER_CONTAINER_NAME} 
MARIADB_SERVER_OPTS += -p ${MARIADB_PORT}:3306 
MARIADB_SERVER_OPTS += -v ${MARIADB_DIR}/data:/var/lib/mariadb 

#MariaDB User and DB command line options
MARIADB_USER_OPTS = -e MARIADB_USER=${MARIADB_USER} 
MARIADB_USER_OPTS += -e MARIADB_PASSWORD_FILE=${MARIADB_PASSWORD_FILE} 
MARIADB_USER_OPTS += -e MARIADB_DATABASE=${MARIADB_DATABASE} 

#Command to open a root mariadb session on the running container  
MARIADB = docker exec -it $(docker ps | grep "forensick-db" | awk '{print $1}') mariadb -h 127.0.0.1 -u root -pawesomerootpassword

##################################### RUN SERVER AND OTHER RUN FUNCTIONS #################################


#Runs the MariaDB Server
mariadb-run:
	-@docker stack deploy -c docker-compose.yml forensick-db

#Stops the MariaDB Server
mariadb-stop:
	-@docker stack rm forensick-db
	
#Hop into the shell and connect to the local database
mariadb-shell:
	$(MARIADB)


################################### DUMP / IMPORT DATA ######################################
#You must add the MARIADB_DUMP_FILE yourself and it should be a gzipped version of the GlobAllomeTree db
#This uses env vars to avoid the password prompt
#To use a different dump file, override the MARIADB_DUMP_FILE variable when calling Make
#ex) make mariadb-import-db MARIADB_DUMP_FILE=../globallometree.import.sql.2.gz
#Note that $(MARIADB) is defined at the beginning of the Makefile but evaluated when used below
mariadb-import-db: 
	gunzip -c $(MARIADB_DUMP_FILE) | $(MARIADB)


# TODO : adapt with `mysqldump` inside the running container + copy from container to host instead
# mariadb-dump-db:
# 	PGPASSWORD=$(POSTGRESQL_PASS) pg_dump -U $(POSTGRESQL_USER) -h $(shell ${PSQL_DIR}/ip_for.sh ${PSQL_SERVER_CONTAINER_NAME}) $(POSTGRESQL_DB) | gzip > $(POSTGRESQL_DB).dump.`date +'%Y_%m_%d'`.sql.gz
# 	@echo "database exported to ${MARIADB_DATABASE}.`date +'%Y_%m_%d'`.sql.gz"


##################################### DOCKER BUILD AND SERVER INIT UTILS #################################

# We don't want to pass sensitive password around, so instead we will create Docker secrets
mariadb-secrets:
	printf "awesomeforensickpassword" | docker secret create mariadb_forensick_forensick_password -
	printf "awesomerootpassword" | docker secret create mariadb_forensick_root_password -

mariadb-init: mariadb-stop mariadb-make-data-dir mariadb-run mariadb-sleep10 mariadb-create-db  


#Force mariadb to reinitialize everything which happens in the docker mariadb id db not initialized
mariadb-delete-data-dir:
	rm -rf ${MARIADB_DIR}/data 


mariadb-make-data-dir:
	mkdir -p ${MARIADB_DIR}/data

#This does a full reset of mariadb from a dump file
#To use a different dump file, override the MARIADB_DUMP_FILE variable when calling Make
#ex) make mariadb-reset-all MARAIDB_DUMP_FILE=../globallometree.import.sql.2.gz
mariadb-reset-all: mariadb-clean mariadb-delete-data-dir mariadb-init 


mariadb-sleep10:
	sleep 10
