# Setting up the database

* Init a docker swarn to handle docker secrets : `docker swam init --advertise-addr <IP_ADDR>`
* `make mariadb-secrets` : create docker secrets used for database access
* `mariadb-make-data-dir` : create volume to mount MariaDB's data on host.
* Start the database : `make mariadb-run`
* You can direclty open a root MariaDB session to manage database manually : `make mariadb-shell`
* You can teardown the database with : `make mariadb-stop`

## Import/Dump DB

* `make mariadb-import` : you can import an `*.sql.gz` archive to seed the `forensick` database.

* TODO : `make mariadb-dump` (will be able to download DB to host) 