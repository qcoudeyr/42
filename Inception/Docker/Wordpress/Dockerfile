# Use Alpine 3.19.1 as the base image
FROM alpine:3.19.1

# Install PHP and required extensions for WordPress
RUN apk add --no-cache curl

# Download and extract WordPress
RUN curl -o wordpress.tar.gz -SL https://wordpress.org/latest.tar.gz \
    && tar -xzf wordpress.tar.gz -C /var/www \
    && rm wordpress.tar.gz \
    && chown -R nobody.nobody /var/www/wordpress

# Expose the volume
VOLUME /var/www/wordpress

# Expose the port PHP-FPM is reachable on
EXPOSE 9000

# Start PHP-FPM
CMD ["php-fpm7", "-F"]
