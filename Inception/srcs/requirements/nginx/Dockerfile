FROM alpine:3.19.1

RUN apk add --update --no-cache alpine-sdk \
	nano \
	curl \
	sudo \
	openssl \
	pcre \
	pcre-dev \
	zlib-dev \
	openssl-dev \
	gd-dev

RUN mkdir -p /tmp/nginx \
	&& cd /tmp/nginx \
	&& curl -o nginx.tar.gz -SL https://nginx.org/download/nginx-1.20.1.tar.gz \
	&& tar -xzf nginx.tar.gz --strip-components=1 \
	&& rm nginx.tar.gz \
	&& curl -o ngx_http_redis-0.3.9.tar.gz https://people.freebsd.org/~osa/ngx_http_redis-0.3.9.tar.gz \
	&& tar -xzf ngx_http_redis-0.3.9.tar.gz \
	&& rm ngx_http_redis-0.3.9.tar.gz \
	&& chown -R nobody:nobody /tmp/nginx \
	&& ./configure --prefix=/var/www/  --sbin-path=/usr/sbin/nginx --conf-path=/etc/nginx/nginx.conf --http-log-path=/var/log/nginx/access.log --error-log-path=/var/log/nginx/error.log --with-pcre  --lock-path=/var/lock/nginx.lock --pid-path=/var/run/nginx.pid --with-http_ssl_module --with-http_image_filter_module=dynamic --modules-path=/etc/nginx/modules --with-http_v2_module --with-stream=dynamic --with-http_addition_module --with-http_mp4_module --add-module=/tmp/nginx/ngx_http_redis-0.3.9 --with-openssl-opt="no-deprecated" \
	&& make CFLAGS="-Wno-error=deprecated-declarations" \
	&& make install



RUN mkdir -p /run/nginx  /var/www/qcoudeyr.42.fr/cache /srv/temp/nginx/client_body_temp /srv/temp/nginx/proxy_temp /srv/temp/nginx/uwsgi_temp /srv/temp/nginx/fastcgi_temp

# Generate a self-signed SSL certificate and key
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=FR/ST=Occitanie/L=Perpignana/O=Dis/CN=*pro.qcoudeyr.42.fr"

# Configure Nginx to use the generated SSL certificate and key
# and to use TLS v1.3

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]
