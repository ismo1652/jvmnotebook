#################################################
# Makefile for OpenJDK Hotspot Runtime
#################################################

JVM_INCL = -I. -Ivm/asm -Ivm/c1 -Ivm/ci -Ivm/classfile -Ivm/code -Ivm/compiler -Ivm/gc_implementation -Ivm/gc_implementation/concurrentMarkSweep -Ivm/gc_implementation/shared -Ivm/gc_implementation/g1 -Ivm/gc_implementation/parallelScavenge -Ivm/gc_implementation/parNew -Ivm/gc_interface -Ivm/interpreter -Ivm/libadt -Ivm/memory -Ivm/oops -Ivm/opto -Ivm/prims -Ivm/runtime -Ivm/services -Ivm/shark -Ivm/utilities -DHOTSPOT_RELEASE_VERSION="\"19.0-b09\"" -DHOTSPOT_BUILD_TARGET="\"product\"" -DHOTSPOT_BUILD_USER="\"developer\"" -DHOTSPOT_LIB_ARCH=\"i386\" -DJRE_RELEASE_VERSION="\"1.6.0-internal-developer_11_jun_2011_19_45-b00\"" -DHOTSPOT_VM_DISTRO="\"OpenJDK\"" -DCOMPILER2 -DCOMPILER1 -D_REENTRANT  -DVM_LITTLE_ENDIAN 
CXXFLAGS = -DLINUX -D_GNU_SOURCE -DIA32 -DPRODUCT $(JVM_INCL) -O3 -g -Wall -fmessage-length=0 -fno-strict-aliasing -Werror -Wpointer-arith -Wsign-compare

OBJS = src/JavaHotSpotSrc.o

PRECOMPILED_HEADER=incls/_precompiled.incl.gch

LIBS =

TARGET = JavaHotSpotSrc.exe

$(TARGET):	$(PRECOMPILED_HEADER) $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)


# read a generated file defining the set of .o's and the .o .h dependencies
include Dependencies

# Rule for building precompiled header
# make/linux/makefiles/gcc.make:PRECOMPILED_HEADER=$(PRECOMPILED_HEADER_DIR) 
#
$(PRECOMPILED_HEADER): $(Precompiled_Files)
	echo Generating precompiled header $@
	mkdir -p incls
	$(CXX) -x c++-header -c incls/_precompiled.incl -o $@ $(COMPILE_DONE)

# making 

#################################################
# Dependencies
#################################################

# src/vm/memory/allocation.hpp: src/vm/c1/c1_globals.hpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: default vm_build_preliminaries
.PHONY: lists ad_stuff jvmti_stuff sa_stuff the_vm clean realclean
.PHONY: checks check_os_version install
.PHONY: default build install install_jvm