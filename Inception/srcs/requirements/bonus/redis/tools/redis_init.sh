#!/bin/sh
set -e

echo 'Start redis-server'
redis-server

echo 'Set the redis pass using the env var'

redis-cli config set requirepass '$REDIS_PASS'

# Hand over control to the main CMD
exec "$@"
