FROM alpine:3.19.1

RUN  apk add openssl curl ca-certificates

RUN printf "%s%s%s%s\n" \
    "@nginx " \
    "http://nginx.org/packages/alpine/v" \
    `egrep -o '^[0-9]+\.[0-9]+' /etc/alpine-release` \
    "/main" \
    |  tee -a /etc/apk/repositories

RUN curl -o /tmp/nginx_signing.rsa.pub https://nginx.org/keys/nginx_signing.rsa.pub

RUN openssl rsa -pubin -in /tmp/nginx_signing.rsa.pub -text -noout

RUN  mv /tmp/nginx_signing.rsa.pub /etc/apk/keys/

RUN  apk add nginx@nginx

RUN  apk add nginx-module-image-filter@nginx nginx-module-njs@nginx

RUN mkdir -p /run/nginx

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=Denial/L=Springfield/O=Dis/CN=qcoudeyr.io"


RUN echo 'http {\
    server {\
        listen              443 ssl;\
        server_name         localhost;\
        ssl_certificate     /etc/ssl/certs/nginx-selfsigned.crt;\
        ssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;\
        ssl_protocols       TLSv1.2 TLSv1.3;\
        ssl_ciphers         TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384;\
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
