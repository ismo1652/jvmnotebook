#! /usr/bin/python
##
## Recurive glob example
## 9/29/2006
## hosted by: Berlin Brown
##
## Modifications 11/10/2006:
## Write out only *.gz files
##
## jython -c "import blb.DirAll as b;b.main()" -v
##

import os
import glob
import sys
import fnmatch
import traceback

#
# Globals 
pathaccess_ctr = 0

def glob_get_dirs(path):
    ''' Return a list of directorie at this particular path '''
    global pathaccess_ctr

    d = []
    pathaccess_ctr = pathaccess_ctr + 1
        
    try:
        for i in os.listdir(path):          
            if os.path.isdir(path+i):
                d.append(os.path.basename(i))

    except NameError, ne:
        print "NameError thrown=", ne
    except:
        # Print the error message including line numbers
        print "\nERR Description: ", sys.exc_info()[0]
        print "-----------------------"
        print ''.join(traceback.format_exception(
            *sys.exc_info())[-2:]).strip().replace('\n',': ')
        print "ERR in get_dirs()"
        print "-----------------------"

    return d

def rec_glob(path, mask):
    ''' Recursive glob on the following path '''
    l = []
    if path[-1] != '\\':
        path = path + '/'
        
    for i in glob_get_dirs(path):
        res = rec_glob(path + i, mask)
        l = l + res
        
    try:
        for i in os.listdir(path):
            ii = i
            i = path + i
            if os.path.isfile(i):
                if fnmatch.fnmatch(ii, mask):
                    l.append(i)

    except NameError, ne:
        print "NameError thrown=", ne
    except:
        print sys.exc_info()[0]
        print "ERR in rec_glob()"

    return l    

def main():
    import getopt

    sysargs = sys.argv
    optlist, args = getopt.getopt(sysargs[1:], "i:e:v")
    # print "Args=", optlist, args
    # print "usage: -i [INPUT FILE] -e [GLOB EXPRESSION] -v {VERBOSITY setting}"

    inpath = "./"
    expr = "*.*"
    for (option, value) in optlist:  
        if option == '-i':            
            inpath = value
        elif option == '-e':
            expr = value

    z = rec_glob(inpath, expr)      
    if z:                   
        for n in z:
            # Split the string by '/' path and '.'
            arr_file = n.split('/')
            # Only extract the filename
            last_i = len(arr_file) - 1
            filename = arr_file[last_i:][0]
            split_filename = filename.split('.')
            filename_only = split_filename[0]
            filename_ext = split_filename[1]
                    
            print "# Processing ", filename_only
            print "cp %s ./dump" % (n)
            print "mkdir -pv ./dump/%s" % (filename_only)
            if filename_ext == 'zip':
                print "unzip -q ./dump/%s -d ./dump/%s" % (filename, filename_only)
            elif filename_ext == 'tar':
                print "tar -xf ./dump/%s -C ./dump/%s" % (filename, filename_only)
            else:
                print "#### Invalid Filename ####"
                
                
            
    else:
        print "INFO: Invalid dir scan, no files found"

    print "# done"    

if __name__ == '__main__':
    main()

# End of the File                       
