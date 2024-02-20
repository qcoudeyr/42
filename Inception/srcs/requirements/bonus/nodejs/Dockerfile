FROM alpine:3.19.1

RUN addgroup -S node && adduser -S -g node node

RUN apk add npm --no-cache

RUN mkdir -p /home/node/app/node_modules && chown -R node:node /home/node/app

WORKDIR /home/node/app

COPY ./tools/node_website/ .

RUN chmod 777 -R *

USER node

RUN npm install


COPY --chown=node:node ./tools/node_website/ .

EXPOSE 8080

CMD [ "node", "app.js" ]
