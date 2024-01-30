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


