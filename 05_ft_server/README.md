# ft_server

Using Docker to install a simple web server in only one docker container.\
It runs multiples services: Wordpress, phpMyAdmin, and a SQL database.\
The container OS is Debian Buster.

<br/>

## Docker commands

To build the docker image:

    docker build -t ft_server_image .

To run the container:

    docker run --name ft_server -it -p 80:80 -p 443:443 ft_server_image

Check if it is working by accessing `https://localhost`.

To switch the nginx autoindex on/off, in a new terminal:

    docker exec ft_server bash /root/autoindex.sh

To stop container:

    docker stop ft_server

To delete container and image:
```
docker rm ft_server
docker rmi ft_server_image
```

If the Debian image is not needed, delete it too:

    docker rmi debian:buster

<br/>

PS:\
When using 42's VMLinux, before running the docker container, you need to stop VM's nginx because it is already using the 80:80 port.

To stop nginx:

    service nginx stop
