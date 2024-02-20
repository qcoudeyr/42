# Use Alpine Linux as the base image
FROM alpine:3.19.1

# Install Adminer and PHP
RUN apk add --no-cache  php83 php83-pdo_mysql

# Set environment variables for database connection
ENV SQL_DATABASE=my_database
ENV SQL_USER=my_user
ENV SQL_PASSWORD=my_password
ENV SQL_ROOT_PASSWORD=my_root_password
ENV SQL_HOST=my_host

# Expose port 8080 for Adminer
EXPOSE 8080

# Start Adminer with PHP built-in server
CMD [ ]
