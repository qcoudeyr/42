SHELL := /bin/bash

all: install-docker check-directories generate-ssh-keys install_ssl_certificate build-and-up generate-ssh-keys check-and-add-host

HOST_ENTRY="10.0.20.10 qcoudeyr.42.fr wordpress.qcoudeyr.42.fr"

install_ssl_certificate:
	@which mkcert || (echo "mkcert not found. Installing..." && sudo apt-get install mkcert)
	@which certutil || (echo "libnss3-tools not found. Installing..." && sudo apt-get install libnss3-tools)
	@mkcert -cert-file ./srcs/requirements/nginx/tools/qcoudeyr.42.fr.crt -key-file ./srcs/requirements/nginx/tools/qcoudeyr.42.fr.key qcoudeyr.42.fr "*.qcoudeyr.42.fr"
	@mkcert -install -cert-file ./srcs/requirements/nginx/tools/qcoudeyr.42.fr.crt -key-file ./srcs/requirements/nginx/tools/qcoudeyr.42.fr.key

check-and-add-host:
	@if ! grep -Fq $(HOST_ENTRY) /etc/hosts; then \
		echo "Adding entry to /etc/hosts"; \
		echo $(HOST_ENTRY) | sudo tee -a /etc/hosts; \
	else \
		echo "Entry already exists in /etc/hosts"; \
	fi

install-docker:
	@if ! command -v docker &> /dev/null; then \
		echo "Docker is not installed. Installing Docker..."; \
		sudo apt-get update && sudo apt-get install -y docker.io; \
		sudo usermod -aG docker $(USER); \
		newgrp docker; \
		echo "Docker installed successfully."; \
	else \
		echo "Docker is already installed."; \
	fi

check-env:
	@if [ ! -d ./scrs/.env" ]; then \
		echo " No .env file find at ./scrs/.env !!!"; \
		echo "Build when "; \
	else \
		echo "$(HOME)/data/inception_mariadb directory already exists."; \
	fi

check-directories:
	@if [ ! -d "$(HOME)/data/inception_mariadb" ]; then \
		echo "Creating $(HOME)/data/inception_mariadb directory..."; \
		mkdir -p $(HOME)/data/inception_mariadb; \
		echo "$(HOME)/data/inception_mariadb directory created."; \
	else \
		echo "$(HOME)/data/inception_mariadb directory already exists."; \
	fi
	@if [ ! -d "$(HOME)/data/inception_wordpress" ]; then \
		echo "Creating $(HOME)/data/inception_wordpress directory..."; \
		mkdir -p $(HOME)/data/inception_wordpress; \
		echo "$(HOME)/data/inception_wordpress directory created."; \
	else \
		echo "$(HOME)/data/inception_wordpress directory already exists."; \
	fi

generate-ssh-keys:
	@if [ ! -f "./srcs/requirements/bonus/sftp/tools/ssh_host_ed25519_key" ]; then \
		echo "Generating SSH keys..."; \
		ssh-keygen -t ed25519 -f ./srcs/requirements/bonus/sftp/tools/ssh_host_ed25519_key < /dev/null; \
	else \
		echo "ssh_host_ed25519_key already exists."; \
	fi
	@if [ ! -f "./srcs/requirements/bonus/sftp/tools/ssh_host_rsa_key" ]; then \
		echo "Generating SSH keys..."; \
		ssh-keygen -t rsa -b 4096 -f ./srcs/requirements/bonus/sftp/tools/ssh_host_rsa_key < /dev/null; \
	else \
		echo "ssh_host_rsa_key already exists."; \
	fi
	@chmod 640 ./srcs/requirements/bonus/sftp/tools/ssh_host_ed25519_key ./srcs/requirements/bonus/sftp/tools/ssh_host_rsa_key
	@echo "SSH keys generated and permissions set. Keys placed in ./srcs/requirements/bonus/sftp/tools/"

build-and-up:
	@cd ./srcs && sudo docker-compose up --build -d

fclean:
	@cd ./srcs && sudo docker-compose down && cd ../
	@sudo docker system prune -af
	@echo "Checking for volumes..."
	@if sudo docker volume ls | grep -q "srcs"; then \
		echo "Removing volumes..."; \
		sudo docker volume rm srcs_mariadb_volume srcs_wordpress_volume; \
	else \
		echo "No volumes found."; \
	fi
	@echo "Docker cleaning is done !";
	@if [ -f "./srcs/requirements/bonus/sftp/tools/ssh_host_rsa_key" ]; then \
		echo "Cleaning SSH key files..."; \
		sudo rm -rf ./srcs/requirements/bonus/sftp/tools/ssh*; \
	fi
	@if [ -d "$(HOME)/data" ]; then \
		echo "Cleaning data folder..."; \
		sudo rm -rf $(HOME)/data ;\
	fi
	@echo "Cleaning is done !";

re: fclean all

.PHONY: all install-docker check-directories build-and-up generate-ssh-keys fclean re
