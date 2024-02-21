#!/bin/sh

# Set your domain names and email
DOMAIN_NAME="qcoudeyr.42.fr"
WWW_DOMAIN_NAME="www.qcoudeyr.42.fr"
EMAIL="qcoudeyr@student.42perpignan.fr"

# Request the initial certificate
certbot certonly --webroot -w /var/www/letsencrypt -d $DOMAIN_NAME -d $WWW_DOMAIN_NAME \
    --email $EMAIL -n --agree-tos

# Set up the automatic certificate renewal
echo "0 3 1 * * certbot renew --webroot -w /var/www/letsencrypt --post-hook 'echo Certificate renewed && touch /app/cert_updated'" > /etc/crontabs/root

# Start cron daemon in the foreground
exec crond -f -l 0
