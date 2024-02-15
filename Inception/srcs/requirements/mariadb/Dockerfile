# Use Alpine 3.19.1 as the base image
FROM alpine:3.19.1

# Install MariaDB (MySQL) server
RUN apk add --no-cache mariadb mariadb-client

# Copy the entrypoint script into the container
COPY ./tools/entrypoint.sh /usr/local/bin/

# Make the entrypoint executable
RUN chmod 777 /usr/local/bin/entrypoint.sh

# Set the entrypoint

# Define the data directory as a volume
VOLUME /var/lib/wordpress_db

# Expose the port MariaDB listens on
EXPOSE 3306

# Copy the custom MariaDB config
COPY ./conf/wordpress_db.cnf /etc/mysql/my.cnf

# Start the MariaDB server
CMD ["mysqld"]
