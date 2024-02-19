#!/bin/sh
set -e

echo 'Set the redis pass using the env var'

check_and_create_folder() {
    if [ -d "$1" ]; then
        echo "Folder '$1' already exists."
    else
        mkdir -p "$1"
        echo "Folder '$1' created successfully."
    fi
}

check_and_create_folder "/etc/redis/"

# Set the redis password using the environment variable REDIS_PASS
if [ -n "$REDIS_PASS" ]; then
    echo "requirepass $REDIS_PASS" >> /etc/redis/redis.conf
    echo "Redis password set successfully in /etc/redis/redis.conf."
else
    echo "Error: REDIS_PASS environment variable is not set."
    exit 1
fi


# Hand over control to the main CMD
exec "$@"
