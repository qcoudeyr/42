#!/bin/sh
set -e
# MariaDB configuration script for WordPress

# Wait for MariaDB to start
until mysqladmin ping; do
    echo 'Waiting for MariaDB to start...'
    sleep 1
done
echo 'MariaDB started'

# Secure the MariaDB installation (similar to 'mysql_secure_installation')
mysql -u root -p"$SQL_ROOT_PASSWORD"  <<-EOSQL
    SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$SQL_ROOT_PASSWORD');
    DELETE FROM mysql.user WHERE User='';
    DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
    DROP DATABASE IF EXISTS test;
    DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
    FLUSH PRIVILEGES;
EOSQL

# Create WordPress database
mysql -u root -p"$SQL_ROOT_PASSWORD"  <<-EOSQL
    CREATE DATABASE IF NOT EXISTS \`$SQL_DATABASE\` CHARACTER SET $SQL_CHARSET COLLATE $SQL_COLLATION;
EOSQL

# Create WordPress user
mysql -u root -p"$SQL_ROOT_PASSWORD"  <<-EOSQL
    CREATE USER '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';
    GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_USER'@'%';
    FLUSH PRIVILEGES;
EOSQL

# Create an additional user with a username not containing 'admin' or 'administrator'
# Replace 'nonadminuser' and 'nonadminpassword' with the desired username and password
mysql -u root -p"$SQL_ROOT_PASSWORD"  <<-EOSQL
    CREATE USER '$SQL_ADDITIONAL_USER'@'%' IDENTIFIED BY '$SQL_ADDITIONAL_PASSWORD';
    GRANT ALL PRIVILEGES ON \`$SQL_DATABASE\`.* TO '$SQL_ADDITIONAL_USER'@'%';
    FLUSH PRIVILEGES;
EOSQL

echo 'MariaDB configuration completed'

# Hand off to the original entrypoint (to ensure that the original behavior of the image is preserved)
exec "$@"
