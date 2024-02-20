FROM alpine:3.19.1

RUN apk add --update --no-cache certbot tzdata

# Change your timezone if needed
ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Create the challenge files directory
RUN mkdir -p /var/www/letsencrypt

# Set the current working directory
WORKDIR /app

# Copy the script to the container
COPY ./tools/request_certificate.sh /app/request_certificate.sh

# Make it executable
RUN chmod +x /app/request_certificate.sh

# Run the certificate request script
CMD ["/app/request_certificate.sh"]
