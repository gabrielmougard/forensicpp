
/*
    1) then set database name and username to create you need databases
        example: .env MYSQL_USER=appuser and need db name is myshop_db

    this sql script is auto run when mariadb container start and $DATA_PATH_HOST/mariadb not exists.
    if your $DATA_PATH_HOST/mariadb is exists and you do not want to delete it, you can run by manual execution:

    docker-compose exec mariadb bash
    mysql -u root -p < /docker-entrypoint-initdb.d/createdb.sql
*/

CREATE DATABASE IF NOT EXISTS `forensick` COLLATE 'utf8_general_ci' ;
GRANT ALL ON `forensick`.* TO 'root'@'%' ;
GRANT ALL ON `forensick`.* TO 'forensick'@'%' ;

FLUSH PRIVILEGES ;