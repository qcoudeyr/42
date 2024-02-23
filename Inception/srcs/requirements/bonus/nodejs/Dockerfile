FROM alpine:3.19.1

RUN addgroup -S node && adduser -S -g node node

RUN apk add npm --no-cache

RUN mkdir  /home/node/app/  /home/node/app/views

RUN chown -R node:node /home/node/app

WORKDIR /home/node/app

COPY ./tools/node_website/app.js /home/node/app
COPY ./tools/node_website/package.json /home/node/app
COPY ./tools/node_website/views/ /home/node/app/views/

RUN chmod 777 -R *

USER node

RUN npm install

EXPOSE 8080

CMD [ "node", "app.js" ]
