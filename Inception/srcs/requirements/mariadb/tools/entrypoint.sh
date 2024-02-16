#!/bin/sh
set -e

# Start the MariaDB server in the background
mysqld_safe &
pid="$!"

# Wait for MariaDB to start
until mysqladmin ping &>/dev/null; do
    echo 'Waiting for MariaDB to become available...'
    sleep 1
done
echo 'MariaDB is available'

# Perform the security steps similar to mysql_secure_installation
mysql --user=root <<-EOF
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

# Create the user and database
mysql --user=root --password="$SQL_ROOT_PASSWORD" <<-EOSQL
CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\`;
CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';
GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_USER'@'%';
FLUSH PRIVILEGES;
EOSQL

echo 'MySQL setup completed'

# Stop the service before exiting
service mysql stop

# Hand over control to the main CMD
exec "$@"
