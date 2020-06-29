#!/bin/bash

FILE=/etc/nginx/sites-available/default
AUTOINDEX_STATUS=$(grep -m 1 "autoindex" $FILE | cut -d " " -f 2 | sed 's/;//')

echo ""
echo "The autoindex is set to ${AUTOINDEX_STATUS^^}"
echo ""
echo "Switching autoindex..."

if [ $AUTOINDEX_STATUS = "on" ]
then
	sed -i '/autoindex/ s/on/off/' $FILE
else
	sed -i '/autoindex/ s/off/on/' $FILE
fi

# reload nginx
/etc/init.d/nginx reload

AUTOINDEX_STATUS=$(grep -m 1 "autoindex" $FILE | cut -d " " -f 2 | sed 's/;//')
echo ""
echo "The autoindex is now set to ${AUTOINDEX_STATUS^^}"
echo ""
