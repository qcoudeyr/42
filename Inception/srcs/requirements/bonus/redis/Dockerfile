FROM alpine:3.19.1

RUN apk add --update redis

COPY ./tools/redis_init.sh /

RUN chmod +x /redis_init.sh

ENTRYPOINT [ "/redis_init.sh" ]

CMD [ "redis-server" ]
