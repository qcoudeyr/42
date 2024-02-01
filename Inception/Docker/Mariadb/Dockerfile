FROM alpine:3.19.1

RUN apk add --no-cache mariadb mariadb-client

RUN mkdir /scripts
COPY ./init_db.sh /scripts/init_db.sh
RUN chmod +x /scripts/init_db.sh
RUN /scripts/init_db.sh

VOLUME /var/lib/mysql

EXPOSE 3306

COPY my.cnf /etc/mysql/my.cnf

CMD ["mysqld_safe"]
