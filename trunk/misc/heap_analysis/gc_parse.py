########################################
# Berlin Brown
# Simple python script for parsing the garbage collection output
# 12/21/2008
#
# The following arguments were passed to the JVM:
# java -verbosegc -verbosegc -verbosegc
#   -XX:+PrintGCDetails -XX:+PrintGCTimeStamps CrashJVM -Xms24MB -Xmx32MB > gc_anal.txt
#
# Tested with:
#
# java version "1.6.0_10"
# Java(TM) SE Runtime Environment (build 1.6.0_10-b33)
# Java HotSpot(TM) Client VM (build 11.0-b15, mixed mode, sharing)
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
DEFAULT_FILENAME        = "gc_normal_anal.txt"
DEFAULT_OUTPUT_FILENAME = "image_gc_analysis.txt"

TIME_IDX              = 2
DEF_START_OCC_IDX     = 3 
DEF_END_OCC_IDX       = 5
NEW_SUBGROUP_IDX      = 7

SUB_DEF_ALL_IDX       = 1 
SUB_PAUS1_TIME_IDX    = 5
SUB_START_OCC_IDX     = 6
SUB_END_OCC_IDX       = 8

ITER_IDX              = 0 
START1_IDX            = 1
END1_IDX              = 2
ALL_IDX               = 3
PAUS1_IDX             = 4
MAIN_START_OCC_IDX    = 5
MAIN_END_OCC_IDX      = 6
MAIN_PAUS_IDX         = 7

GNU_PLOT_GC_HEADERS = [
	'gc_iter',
	'gc_defnew_start',
	'gc_defnew_end',
	'gc_defnew_all',
	'gc_paus_time',
	'gc_start_occ',
	'gc_end_occ',
	'gc_main_paus_time'
	]

def get_gc_stats(pattr, pattr_sub, line):
	pattr_time = re.compile('^(.*), (\S*) secs\] \[Times\:.')	
	# Example subgroup.
	# (1984K), 0.0006890 secs] 23030K->21247K(27320K)
	m = pattr.match(line)
	if (m and (len(m.groups()) > 5)):
		gc_iter = m.group(TIME_IDX)
		gc_new_start = m.group(DEF_START_OCC_IDX)
		gc_new_end = m.group(DEF_END_OCC_IDX)
		subgrp_str = m.group(NEW_SUBGROUP_IDX)

		sub_m = pattr_sub.match(subgrp_str)
		if (sub_m):
			sub_def_all   = sub_m.group(SUB_DEF_ALL_IDX)
			sub_paus_time = sub_m.group(SUB_PAUS1_TIME_IDX)
			sub_start_occ = sub_m.group(SUB_START_OCC_IDX)
			sub_end_occ   = sub_m.group(SUB_END_OCC_IDX)
		else:
			print "ERR: Invalid subgroup"
			print line
			return None

		m_time = pattr_time.match(line)
		if m_time:
			sub_main_paus_time = m_time.group(2)
		else:
 			print "Invalid pause time subgroup"
			return None

		# Return a tuple of all the fields
		return [ gc_iter,
				 gc_new_start,
				 gc_new_end,
				 sub_def_all,
				 sub_paus_time,
				 sub_start_occ,
				 sub_end_occ,
				 sub_main_paus_time ]
		
def test_regex_parse():
	# Generic unit test for one of the GC lines
	example_line = "Stuff  \nMore stuff here\n9999.200: [GC 28.200: [DefNew: 1921K->137K(1984K), 0.0006890 secs] 23030K->21247K(27320K), 0.0007550 secs] [Times: user=0.00 sys=0.00, real=0.00 secs]\nMore stuff More Stuff\n"
	pattr = re.compile('^(\S*): \[GC (\S*): \[DefNew: (\S*)(K|M)\-\>(\d*)(K|M)(.*)(,) (\S*) secs\].')
	pattr_sub = re.compile('^\((\S*)(K|M)\)(.*)(,) (\S*) secs\] (\S*)(K|M)\-\>(\d*)(K|M).')
	# Break up into a group and then a subgroup
	lines = example_line.split('\n')
	for line_raw in lines:
		line = line_raw.strip()
		get_gc_stats(pattr, pattr_sub, line)
		
def gc_parse(filename, out_filename):
	print "Running parse on file=%s" % (filename)
	finput = open(filename, 'r')
	foutput = open(out_filename, 'w')
	for header in GNU_PLOT_GC_HEADERS:
		foutput.write("%s\t" % header)		
	foutput.write('\n')
	foutput.flush()

	pattr = re.compile('^(\S*): \[GC (\S*): \[DefNew: (\S*)(K|M)\-\>(\d*)(K|M)(.*)(,) (\S*) secs\].')
	pattr_sub = re.compile('^\((\S*)(K|M)\)(.*)(,) (\S*) secs\] (\S*)(K|M)\-\>(\d*)(K|M).')
	
	for line_raw in finput:		
		line = line_raw.strip()
		gc_stats = get_gc_stats(pattr, pattr_sub, line)
		if gc_stats:
			all_str = "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n" % (
				gc_stats[ITER_IDX],
				gc_stats[START1_IDX],
				gc_stats[END1_IDX],
				gc_stats[ALL_IDX],
				gc_stats[PAUS1_IDX],
				gc_stats[MAIN_START_OCC_IDX],
				gc_stats[MAIN_END_OCC_IDX],
				gc_stats[MAIN_PAUS_IDX]
			)
			foutput.write(all_str)
			
	foutput.flush()
			
def main():
	print "Running GC parser, edit the 'DEFAULT_FILENAME' to"
	print "change the file to parse (see gc_parse.py)."
	gc_parse(DEFAULT_FILENAME, DEFAULT_OUTPUT_FILENAME)	

if __name__ == '__main__':
	main()

# End of script
