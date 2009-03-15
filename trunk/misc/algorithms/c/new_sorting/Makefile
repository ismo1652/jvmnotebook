#######################################################################
#
######################################################################

DEBUG_ON = -g
DEBUG_OFF = 
DEBUG_STATE = $(DEBUG_OFF)

GCC = gcc
INCLUDE = -I/usr/include/
CFLAGS = -Wall $(INCLUDE)

##############################
# Main Application
##############################
PROG  = insert_sort
PROG2 = quick_sort

all: $(PROG) $(PROG2)

##############################
# Object Files
##############################
OBJS = insert_sort.o          	\

OBJS2 = quick_sort.o            \

##############################
# Program Target and Obj dependencies
##############################
$(PROG): $(OBJS)
	$(GCC) $(CFLAGS) -o $@ $(OBJS) $(LIBDIR) $(LIBS)
	
$(PROG2): $(OBJS2)
	$(GCC) $(CFLAGS) -o $@ $(OBJS2) $(LIBDIR) $(LIBS)

run: $(PROG)
	./$(PROG)
	
run2: $(PROG2)
	./$(PROG2)	

##############################
# Handle C Files to generate object files
##############################
.c.o:
	$(GCC) -O -I. $(INCLUDE) $(DEBUG_STATE) -c -Wall -o $@ $<

##############################
# Clean Garbage Files
##############################
clean: 
	rm -f *.o *~ 

# End of Makefile
