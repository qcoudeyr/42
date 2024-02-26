#!/bin/sh

echo 'Check connection between Wordpress and Mariadb'
until mysqladmin ping -h $SQL_HOST --silent; do
    echo 'Waiting for MariaDB to become available...'
    sleep 1
done
echo 'MariaDB is available'

echo 'Try to connect Worpdress to Mariadb using wp-cli'
until wp config create --dbname="$SQL_DATABASE" --dbuser="$SQL_USER" --dbpass="$SQL_PASSWORD" --dbhost="$SQL_HOST" --allow-root --force; do
    echo 'Waiting for Wordpress to connect to MariaDB...'
    sleep 1
done
echo 'Connected to Mariadb !'

echo 'Setting up Wordpress ...'
wp core install --url="$WP_URL" --title="Qcoudeyr Inception" --admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --skip-email --allow-root
echo 'Wordpress is setup correctly !'

echo 'Configuring the redis-cache plugin before installation'
wp config set WP_REDIS_HOST "redis_container"
wp config set WP_REDIS_PORT "6379"
wp config set WP_REDIS_DATABASE "15"
wp config set WP_REDIS_PASSWORD "$REDIS_PASS"
echo 'Redis Cache configured for Wordpress !'

echo 'Installing Redis Cache plugin for Wordpress'
wp plugin install redis-cache

echo 'Activating the plugin'
wp plugin activate redis-cache

wp redis enable

echo 'Creating non admin user'
wp user create "$WP_ADDITIONAL_USER" email@email.com --user_pass="$WP_ADDITIONAL_PASSWORD"
echo 'User created !'

exec "$@"
