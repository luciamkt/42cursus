#!/bin/bash

# start nginx, mariadb and php
/etc/init.d/nginx start
/etc/init.d/mysql start
/etc/init.d/php7.3-fpm start

echo "
         _
        (:)_
      ,'    \`.
     :        :
     |        |              ___
     |       /|    ______   // _\\
     ; -  _,' :  ,'      \`. \\   -\\
    /          \\/          \\ \\   :
   (            :  ------.  \`-'  |
____\___    ____|______   \______|_______
        |::|           '--\`           
        |::|
        |::|
        |::|
        |::|
        \\::/
"
