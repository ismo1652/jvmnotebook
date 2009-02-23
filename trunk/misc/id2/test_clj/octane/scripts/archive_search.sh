#!/bin/sh
#
# Invoke the hello world script

cd ../

echo "*****************"
echo "Script: note : use '1', '2', '3' as the first arg to the script"
echo "*****************"

./octscripts.sh scripts/scripts/archive_search.clj $1 $2 $3 $4 $5
