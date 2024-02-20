# Use Alpine Linux as the base image
FROM alpine:3.19.1

# Install Adminer and PHP
RUN apk add --no-cache

# Expose port 8080 for Adminer
EXPOSE 8080

# Start Adminer with PHP built-in server
CMD [ "php", "-S" , "0.0.0.0:8080", "/usr/share/adminer/adminer.php"]
