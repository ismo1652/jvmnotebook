#!/bin/python
######################################################################
#
# Description:
#      Build a skeleton database XML file based on a directory listing 
#      file.
######################################################################

import sys

HEADER='''<?xml version="1.0" encoding="UTF-8"?>
<octane_file_database>
<description>
<![CDATA[
Database File
]]>
</description>
<file_set>
'''

FOOTER='''</file_set>
</octane_file_database>
'''

def print_xml_header():
    print HEADER

def print_xml_footer():
    print FOOTER

def parse_file_list(file_path):
    f = open(file_path, 'r')
    lines = f.readlines()
    print_xml_header()
    for line in lines:
        print '<db_file>'
        print " <file_name>%s</file_name>"            % line.strip()
        print " <file_path>%s</file_path>"            % line.strip()
        print " <file_group>Group</file_group>"
        print " <file_server>localhost</file_server>"
        print " <file_descr>None</file_descr>"
        print '</db_file>'

    print_xml_footer()
    return
    
def main():
    if len(sys.argv) != 2:
        print "ERR: Invalid Arguments"
        print "usage: database_builder.py <input database file listing>"
        sys.exit(-1)

    parse_file_list(sys.argv[1])

if __name__ == '__main__':
    main()

###########################
# End of Script
###########################
