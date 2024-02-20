# Use Alpine Linux as the base image
FROM alpine:3.19.1

# Install Adminer and PHP
RUN apk add --no-cache php83 wget

RUN mkdir -p /var/www/
RUN mkdir /var/www/adminer/

WORKDIR /var/www/adminer

RUN wget https://github.com/vrana/adminer/releases/download/v4.8.1/adminer-4.8.1.php

# Expose port 8080 for Adminer
EXPOSE 8080

# Start Adminer with PHP built-in server
CMD [ "php83", "-S" , "0.0.0.0:8080", "/var/www/adminer/adminer-4.8.1.php"]
