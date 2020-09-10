#!/bin/bash

mkdir -p /etc/mysql/conf.d
echo "[mysqld]" > /etc/mysql/conf.d/custom.cnf
echo "max_connections=250" >> /etc/mysql/conf.d/custom.cnf

docker run -d \
	--name=mysql \
	-e "MYSQL_ROOT_PASSWORD=secret-password-1337" \
	-p 3306:3306 \
	-v /etc/mysql/conf.d:/etc/mysql/conf.d \
	mysql

cat setup.sh

# After this step, log in to the container with the help of the following command:
# docker exec -it mysql bash
#
# Log in to mysql as root. (With password as entered above)
# mysql -u root -p
#
# Create a user, a database, and grat permissions to the user.
#
# create user 'roerohan' identified by 'password';
# create database main;
# grant all on main.* to 'roerohan';
#
# You're all set, you can log in as 'roerohan' with password as 'password'.
# Exit the container, use the mysql client or 'mycli' (client featuring autocompletion)
#
# mycli -u roerohan -p -h127.0.0.1

