########################################
# Berlin Brown
# Simple python script for parsing the garbage collection output
# 12/21/2008
#
# The following arguments were passed to the JVM:
# java -verbosegc -verbosegc -verbosegc
#   -XX:+PrintGCDetails -XX:+PrintGCTimeStamps CrashJVM -Xms24MB -Xmx32MB > gc_anal.txt
#
# Example Output java 1.5:
# 20.049: [GC 20.049: [DefNew: 1941K->137K(1576K), 0.0014153 secs] 11194K->11117K(1984K), 0.0014628 secs]
# Example Output java 1.6:
# 20.049: [GC 28.200: [DefNew: 1921K->137K(1984K), 0.0006890 secs] 23030K->21247K(27320K), 0.0007550 secs] [Times: user=0.00 sys=0.00, real=0.00 secs]
#
# Tested with:
#
# java version "1.6.0_10"
# Java(TM) SE Runtime Environment (build 1.6.0_10-b33)
# Java HotSpot(TM) Client VM (build 11.0-b15, mixed mode, sharing)
#
#
# Operating System:
#
# Linux houston 2.6.27-9-generic #1 SMP Thu Nov 20 21:57:00 UTC 2008 i686 GNU/Linux
#
# For regex notes, see:
# http://www.amk.ca/python/howto/regex/
#
# http://java.sun.com/docs/hotspot/gc1.4.2/example.html
# The minor collection output for these options produce output of the form
# [GC [<collector>: <starting occupancy1> -> <ending occupancy1>, <pause time1> secs] <starting occupancy3> -> <ending occupancy3>, <pause time3> secs]
########################################

import re

# Edit the following input config variable
# (Try gc_anal.txt or gc_normal_anal.txt)
#DEFAULT_FILENAME        = "gc_anal.txt"
DEFAULT_FILENAME        = "gc_server_anal.txt"
DEFAULT_OUTPUT_FILENAME = "image_gc_analysis.txt"

TIME_IDX              = 2
DEF_START_OCC_IDX     = 3 
DEF_END_OCC_IDX       = 5
NEW_SUBGROUP_IDX      = 7

SUB_DEF_ALL_IDX       = 1 
SUB_PAUS1_TIME_IDX    = 5
SUB_START_OCC_IDX     = 2
SUB_END_OCC_IDX       = 4

SUB_TOTAL_IDX         = 6

# Final Result Data
ITER_IDX              = 0 
START1_IDX            = 1
END1_IDX              = 2
ALL_IDX               = 3
PAUS1_IDX             = 4
MAIN_START_OCC_IDX    = 5
MAIN_END_OCC_IDX      = 6
MAIN_PAUS_IDX         = 7
TOTAL_IDX             = 8

GNU_PLOT_GC_HEADERS = [
	'gc_used_mem_after',
	'gc_total_avail',
	'gc_defnew_end',
	'gc_defnew_all',
	'gc_paus_time',
	'gc_start_occ',
	'gc_end_occ',
	'gc_main_paus_time' ]

def get_gc_stats(line):
        # Group1 = First Iter Value
        # Group2 = Second 'GC' Iter value        
        regex_begin_iter = '^(\S*):\s*\[GC\s*(\S*):\s*'
        # Group 3 = Young Gen Start Occupancy
        # Group 5 = Young Gen End Occupancy
        
        # 87.401: [GC 87.401: [DefNew: 627K->11K(640K), 0.0005744 secs]87.402: [Tenured: 8630K->4171K(8824K), 0.0186768 secs] 8712K->4171K(9464K), 0.0193632 secs]
        
        regex_def_new    = 'Tenured: (\S*)K\->(\S*)'
        regex_full_str   = '%s' % (regex_def_new)
	pattr = re.compile(regex_full_str)
	
        # Group 1 = Main Start Occupancy
        # Group 2 = Main End Occupancy
	pattr_sub = re.compile('(\S*)K\((\S*)K\)')
        
	# Example subgroup.
	# (1984K), 0.0006890 secs] 23030K->21247K(27320K)
	m = pattr.search(line)
		
	if m:
		print m.groups()		
	
	if (m and (len(m.groups()) == 2)):
                print "  Tenured: INFO: Processing line=%s, size=%s" % (line, (len(m.groups())))
                begin1 = m.group(1)
		subgrp_str = m.group(2)                			
		sub_m = pattr_sub.search(subgrp_str)
		
		used1 = 0
		total1 = 0
								                
                if (sub_m and (len(sub_m.groups()) >= 2)):			
			used1   = sub_m.group(1)
			total1  = sub_m.group(2)
					
		else:
			print "ERR: Invalid subgroup"
                        print "ERR: Subgroup Data: %s" % subgrp_str
			return None

		# Return a tuple of all the fields
		return [ used1, total1 ]
        else:
                if m:
                        print "FAILED on line: [%s] groups=%s" % (line, (len(m.groups())))
                        
def test_regex_parse():
	# Generic unit test for one of the GC lines

        # Regex notes:
        # \S = Matches any non-whitespace character.
        # ^ = Matches at the beginning of lines
	#example_line = "Stuff  \nMore stuff here\n9999.200: [GC 28.200: [DefNew: 1921K->137K(1984K), 0.0006890 secs] 23030K->21247K(27320K), 0.0007550 secs] [Times: user=0.00 sys=0.00, real=0.00 secs]\nMore stuff More Stuff\n"
        example_line = "stuff"
        example_line += "\n20.049: [GC 28.200: [DefNew: 1921K->137K(1984K), 0.0006890 secs] 23030K->21247K(27320K), 0.0007550 secs] [Times: user=0.00 sys=0.00, real=0.00 secs]\n"
        example_line += "\n20.049: [GC 22.049: [DefNew: 1941K->137K(1576K), 0.0014153 secs] 11194K->11117K(1984K), 0.0014628 secs]\nHuh\n"
	
	# 87.401: [GC 87.401: [DefNew: 627K->11K(640K), 0.0005744 secs]87.402: [Tenured: 8630K->4171K(8824K), 0.0186768 secs] 8712K->4171K(9464K), 0.0193632 secs]
			
	# Break up into a group and then a subgroup
	lines = example_line.split('\n')
	for line_raw in lines:
		line = line_raw.strip()
		get_gc_stats(line)
		
def gc_parse(filename, out_filename):
	print "Running parse on file=%s" % (filename)
	finput = open(filename, 'r')
	foutput = open(out_filename, 'w')
	for header in GNU_PLOT_GC_HEADERS:
		foutput.write("%s\t" % header)		
	foutput.write('\n')
	foutput.flush()
	
	for line_raw in finput:		
		line = line_raw.strip()
		gc_stats = get_gc_stats(line)
		if gc_stats:
			print gc_stats
			all_str = "%s\t%s\n" % (				
				gc_stats[0],
				gc_stats[1]				
			)
			foutput.write(all_str)
			
	foutput.flush()
			
def main():
	print "Running GC parser, edit the 'DEFAULT_FILENAME' to"
	print "change the file to parse (see gc_parse.py)."
	gc_parse(DEFAULT_FILENAME, DEFAULT_OUTPUT_FILENAME)	
        #test_regex_parse()
        print "*********************************"
        print "Image parse done"
        print "see %s for the final output" % DEFAULT_OUTPUT_FILENAME
        print "*********************************"

if __name__ == '__main__':
	main()

# End of script
