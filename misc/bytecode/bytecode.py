
"""
 Simple Java Class Loader
 (also, look at: reading simple binary file formats)
 Author: Berlin Brown
 Date: 12/25/2007

 Also see: 
 (1) http://java.sun.com/docs/books/jvms/second_edition/html/ClassFile.doc.html
 (2) http://docs.python.org/lib/module-array.html

 u1, u2, and u4 represent an unsigned one-, two-, or four-byte quantities 
  
 C-Style Structure:
<code>
ClassFile {
    	u4 magic;
    	u2 minor_version;
    	u2 major_version;
    	u2 constant_pool_count;
    	cp_info constant_pool[constant_pool_count-1];
    	u2 access_flags;
    	u2 this_class;
    	u2 super_class;
    	u2 interfaces_count;
    	u2 interfaces[interfaces_count];
    	u2 fields_count;
    	field_info fields[fields_count];
    	u2 methods_count;
    	method_info methods[methods_count];
    	u2 attributes_count;
    	attribute_info attributes[attributes_count];
    }
</code>
"""

from array import *
from struct import unpack

class ClassFile:
    def __init__(self):
        self.magic_number_u4 = array('H')
        self.minor_number_u2 = array('H')
        self.major_number_u2 = array('H')
        self.constant_pool_count_u2 = array('H')
        
    def validateEndian(self):
        """Ensure that we are using the proper endian format.
        >L for big endian, <L for little endian. Intel has little-endian format"""
        self.magic_number_u4.byteswap()
        self.minor_number_u2.byteswap()
        self.major_number_u2.byteswap()
        self.constant_pool_count_u2.byteswap()

    def __str__(self):
        return """<<class-file>>:
  magic[0]=%x magic[1]=%x [%x%x]
  major=%x major=%x [%x, %x]
  constant pool count=%xh
<<<end-descr>>""" % (self.magic_number_u4[0], 
                       self.magic_number_u4[1],
                       self.magic_number_u4[0], 
                       self.magic_number_u4[1],
                       self.minor_number_u2[0],
                       self.major_number_u2[0],
                       self.minor_number_u2[0],
                       self.major_number_u2[0],
                       self.constant_pool_count_u2[0])

""" Create the class file singleton """                                       
main_class_obj = ClassFile()

def getClassFile():
    global main_class_obj
    return main_class_obj

def readByteCode(filename):
    c = getClassFile()
    f = open(filename, "rb")
    try:
        c.magic_number_u4.fromfile(f, 2)
        c.minor_number_u2.fromfile(f, 1)
        c.major_number_u2.fromfile(f, 1)
        c.constant_pool_count_u2.fromfile(f, 1)
        c.validateEndian()
        print c
    finally:
        print "closing file=%s" % filename
        f.close()

if __name__ == '__main__':
    print "running class loader"
    readByteCode("TestMyClassFormat.class")
    print "done"
