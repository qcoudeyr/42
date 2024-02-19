#!/bin/sh
set -e

echo 'Start redis-server'
redis-server

echo 'Set the redis pass using the env var'

redis-cli config set requirepass '$REDIS_PASS'

# Find the PID of the redis-server process
REDIS_PID=$(pgrep redis-server)

# Check if the redis-server process is running
if [ -z "$REDIS_PID" ]; then
    echo "Redis server is not running."
else
    echo "Redis server is running with PID: $REDIS_PID"

    # Kill the redis-server process
    kill $REDIS_PID
    echo "Redis server with PID $REDIS_PID has been killed."
fi


# Hand over control to the main CMD
exec "$@"
