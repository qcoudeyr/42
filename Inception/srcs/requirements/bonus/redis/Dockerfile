FROM alpine:3.19.1

RUN apk add --update redis

RUN echo "vm.overcommit_memory = 1" >> /etc/sysctl.conf

CMD [ "redis-server" ]
