FROM alpine:3.19.1

RUN apk update && apk upgrade && apk add --no-cache \
	nginx \
	nano \
	curl \
	sudo \
	openssl

RUN mkdir -p /run/nginx

# Generate a self-signed SSL certificate and key
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=FR/ST=Occitanie/L=Perpignan/O=Dis/CN=qcoudeyr.42.fr"

# Configure Nginx to use the generated SSL certificate and key
# and to use TLS v1.3

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]
