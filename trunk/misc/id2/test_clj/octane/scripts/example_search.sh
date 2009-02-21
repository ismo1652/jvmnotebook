#!/bin/sh
#
# Invoke the hello world script

cd ../

echo "Script: note : use '1', '2', '3' as the first arg to the script"

./octscripts.sh scripts/scripts/example_search_$1.clj $2 $3 $4 $5
