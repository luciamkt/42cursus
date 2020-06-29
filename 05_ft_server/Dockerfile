# getting base image
FROM debian:buster

COPY srcs /root/

# update and install nginx, mariadb, php, openssl and wget
RUN apt-get update && \
	apt-get upgrade -u -y && \
	apt-get install -y nginx \
	mariadb-server \
	php7.3 php7.3-fpm php-mysql php-mbstring php-cli \
	openssl \
	wget

RUN	bash /root/server_config.sh

ENTRYPOINT bash /root/start.sh && tail -f /dev/null
