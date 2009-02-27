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
PROG  = quick_sort
PROG2 = median_sort

all: $(PROG) $(PROG2)

##############################
# Object Files
##############################
OBJS = quick_sort.o          	\
		sort_lib.o			 	\

OBJS_MEDIAN = median_sort.o		\
				sort_lib.o

##############################
# Program Target and Obj dependencies
##############################
$(PROG): $(OBJS)
	$(GCC) $(CFLAGS) -o $@ $(OBJS) $(LIBDIR) $(LIBS)

$(PROG2): $(OBJS_MEDIAN)
	$(GCC) $(CFLAGS) -o $@ $(OBJS_MEDIAN) $(LIBDIR) $(LIBS)

run: $(PROG)
	./$(PROG).exe

run2: $(PROG2)
	./$(PROG2).exe

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
	rm -f $(PROG).exe $(PROG2).exe

# End of Makefile