# Use Alpine 3.19.1 as the base image
FROM alpine:3.19.1

# Install PHP and required extensions for WordPress
RUN apk add --no-cache \
    php7 \
    php7-fpm \
    php7-mysqli \
    php7-json \
    php7-openssl \
    php7-curl \
    php7-zlib \
    php7-xml \
    php7-phar \
    php7-intl \
    php7-dom \
    php7-xmlreader \
    php7-ctype \
    php7-mbstring \
    php7-gd \
    php7-session \
    curl

# Download and extract WordPress
RUN curl -o wordpress.tar.gz -SL https://wordpress.org/latest.tar.gz \
    && tar -xzf wordpress.tar.gz -C /var/www \
    && rm wordpress.tar.gz \
    && chown -R nobody.nobody /var/www/wordpress

# Configure PHP-FPM to listen on a socket
RUN sed -i 's/;listen = 127.0.0.1:9000/listen = \/var\/run\/php7-fpm.sock/' /etc/php7/php-fpm.d/www.conf \
    && sed -i 's/;listen.owner = nobody/listen.owner = nobody/' /etc/php7/php-fpm.d/www.conf \
    && sed -i 's/;listen.group = nobody/listen.group = nobody/' /etc/php7/php-fpm.d/www.conf \
    && sed -i 's/;listen.mode = 0660/listen.mode = 0660/' /etc/php7/php-fpm.d/www.conf

# Expose the volume
VOLUME /var/www/wordpress

# Expose the port PHP-FPM is reachable on
EXPOSE 9000

# Start PHP-FPM
CMD ["php-fpm7", "-F"]
