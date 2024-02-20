# Use Alpine Linux as the base image
FROM alpine:3.19.1

RUN apk add --no-cache certbot

RUN certbot certonly --nginx

CMD ["sleep", "infinity"]
