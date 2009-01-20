#!/bin/python
######################################################################
#
# Description:
#      Build a skeleton database XML file based on a directory listing 
#      file.
######################################################################

import sys

def main():
    print "database_builder.py running"
    if len(sys.argv) != 2:
        print "ERR: Invalid Arguments"
        print "usage: database_builder.py <input database file listing>"
    print "done"

if __name__ == '__main__':
    main()

###########################
# End of Script
###########################
