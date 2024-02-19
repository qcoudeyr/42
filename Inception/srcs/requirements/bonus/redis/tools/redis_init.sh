#!/bin/sh
set -e

echo 'Set the redis pass using the env var'

echo 'requirepass $REDIS_PASS' >> /etc/redis/redis.conf


# Hand over control to the main CMD
exec "$@"
