#!/bin/sh
set -e


# Check if MariaDB has already been configured
if [ ! -f /var/lib/mysql/configured ]; then

	# Start the MariaDB server in the background
	mysqld_safe &
	pid="$!"

	# Wait for MariaDB to start
	until mysqladmin ping --silent; do
		echo 'Waiting for MariaDB to become available...'
		sleep 1
	done
	echo 'MariaDB is available'
	echo '$SQL_ROOT_PASSWORD'
	echo 'Set SQL_PASSWORD for mysql server ROOT user'
	mysql <<-EOSQL
	SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$SQL_ROOT_PASSWORD');
	FLUSH PRIVILEGES;
	EOSQL


	echo 'Adding admin user and normal user'

	mysql <<-EOSQL
	CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';
	GRANT ALL PRIVILEGES ON *.* TO '$SQL_USER'@'%' WITH GRANT OPTION;
	FLUSH PRIVILEGES;
	EOSQL


	echo 'Create the user and database'
	mysql  <<-EOSQL
	CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;
	CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';
	GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_USER'@'%';
	FLUSH PRIVILEGES;
	EOSQL

	echo 'Create the additional user with specific privileges'
	mysql <<-EOSQL
	CREATE USER IF NOT EXISTS '$SQL_ADDITIONAL_USER'@'%' IDENTIFIED BY '$SQL_ADDITIONAL_PASSWORD';
	-- Here you should replace '$SQL_DATABASE' with the actual database name
	GRANT SELECT, INSERT, UPDATE, DELETE ON \`$SQL_DATABASE\`.* TO '$SQL_ADDITIONAL_USER'@'%';
	FLUSH PRIVILEGES;
	EOSQL

	mysql <<-EOF
	-- Set the root password
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD';
	-- Remove anonymous users
	DELETE FROM mysql.user WHERE User='';
	-- Disallow root login remotely
	DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
	-- Remove test database and access to it
	DROP DATABASE IF EXISTS test;
	DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
	-- Reload privilege tables
	FLUSH PRIVILEGES;
	EOF

	echo 'MySQL setup completed'

	touch /var/lib/mysql/configured

	mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

	wait "$pid"

else
	echo 'MariaDB has already been configured. Starting the server...'
fi
# Hand over control to the main CMD
exec "$@"
