# Use Alpine 3.19.1 as the base image
FROM alpine:3.19.1

# Install Nginx and OpenSSL
RUN apk add --no-cache nginx openssl

# Create a directory for Nginx pid file
RUN mkdir -p /run/nginx

# Generate a self-signed SSL certificate and key
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=www.example.com"

# Configure Nginx to use the generated SSL certificate and key
# and to use TLS v1.3
RUN echo 'http {\
    server {\
        listen              443 ssl;\
        server_name         localhost;\
        ssl_certificate     /etc/ssl/certs/nginx-selfsigned.crt;\
        ssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;\
        ssl_protocols       TLSv1.2 TLSv1.3;\
        ssl_ciphers         TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384;\
        # It is recommended to add additional configuration for server security and performance\
        # ...

        location / {\
            root   /usr/share/nginx/html;\
            index  index.html index.htm;\
        }\
    }\
    include /etc/nginx/conf.d/*.conf;\
}' > /etc/nginx/nginx.conf

# Expose port 443 for the HTTPS server
EXPOSE 443

# Start Nginx in the foreground
CMD ["nginx", "-g", "daemon off;"]
