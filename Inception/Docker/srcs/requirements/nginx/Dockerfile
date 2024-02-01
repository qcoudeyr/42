FROM alpine:3.19.1

RUN apk add --no-cache openssl curl ca-certificates

RUN adduser -G www-data -s /bin/sh -D www-data
RUN printf "%s%s%s%s\n" \
    "@nginx " \
    "http://nginx.org/packages/alpine/v" \
    `egrep -o '^[0-9]+\.[0-9]+' /etc/alpine-release` \
    "/main" \
    |  tee -a /etc/apk/repositories

RUN curl -o /tmp/nginx_signing.rsa.pub https://nginx.org/keys/nginx_signing.rsa.pub

RUN openssl rsa -pubin -in /tmp/nginx_signing.rsa.pub -text -noout

RUN  mv /tmp/nginx_signing.rsa.pub /etc/apk/keys/

RUN apk add --no-cache nginx@nginx nginx-module-image-filter@nginx nginx-module-njs@nginx

RUN mkdir -p /run/nginx

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=FR/ST=PO/L=Paris/O=42/OU=42/CN='$DOMAIN_NAME'/UID=qcoudeyr"

RUN mkdir -p /var/run/nginx
RUN mkdir -p /var/www/html

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

COPY ./conf/conf /etc/nginx/nginx.conf

# Expose port 443 for the HTTPS server
EXPOSE 443

# Start Nginx in the foreground
CMD ["nginx", "-g", "daemon off;"]
