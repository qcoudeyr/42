FROM alpine:3.19.1


RUN echo "@community http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories && \
    apk add --no-cache bash shadow@community openssh-server-pam openssh-sftp-server && \
    ln -s /usr/sbin/sshd.pam /usr/sbin/sshd && \
    mkdir -p /var/run/sshd && \
    rm -f /etc/ssh/ssh_host_*key*

COPY tools/ssh_host_ed25519_key /etc/ssh/
COPY tools/ssh_host_ed25519_key.pub /etc/ssh/
COPY tools/ssh_host_rsa_key /etc/ssh/
COPY tools/ssh_host_rsa_key.pub /etc/ssh/
COPY tools/entrypoint /
COPY conf/sshd_config /etc/ssh/sshd_config
COPY tools/create-sftp-user /usr/local/bin/

RUN  chmod +x /etc/ssh/sshd_config /usr/local/bin/create-sftp-user /entrypoint


EXPOSE 22

ENTRYPOINT ["/entrypoint"]
