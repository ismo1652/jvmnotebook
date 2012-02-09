#!/usr/bin/python

# Group errors by time, search between times by day cluster
# Time frame every 10 minutes
#
# http://docs.python.org/library/time.html#time.strptime
# http://docs.python.org/library/time.html#time.strftime

import string
import time
from datetime import datetime

file = "ExceptionLog_my10.txt.time.txt"

f = open(file, 'r')

now = datetime.now()

t_data = {}
n_data = []
tot_i = 0
for i in range(0, 24):
    stp = 0
    for j in range(0, 6):
        n_data.append([i, stp, tot_i])
        t_data[tot_i] = 0
        stp = stp + 10
        tot_i = tot_i + 1        

for x in f:
    y = x.strip()
    if len(y) > 90:
        #tstr = y[62:81].strip()
        tstr = y[66:85].strip()        
        # 2012.01.23:16:00:45 
        mytime = time.strptime(tstr, "%Y.%m.%d:%H:%M:%S")  
        dt_obj = datetime(*mytime[0:6])
        #print mytime.tm_mday

        # Clone the tuple/slice
        #time.struct_time(tm_year=2012, tm_mon=1, tm_mday=23, tm_hour=16, tm_min=0, tm_se
        # c=45, tm_wday=0, tm_yday=23, tm_isdst=-1)        
        for tpl in n_data:
            i = tpl[0]
            mn = tpl[1]
            jj = tpl[2]
            str1 = "%s.%s.%s:%s:%s:%s" % (mytime.tm_year, mytime.tm_mon,
                mytime.tm_mday, i, mn, "00")
            str2 = "%s.%s.%s:%s:%s:%s" % (mytime.tm_year, mytime.tm_mon,
                mytime.tm_mday, i, mn+9, "00")                
            # Time 1
            mytime1 = time.strptime(str1, "%Y.%m.%d:%H:%M:%S")
            dt_obj1 = datetime(*mytime1[0:6])

            mytime2 = time.strptime(str2, "%Y.%m.%d:%H:%M:%S")
            dt_obj2 = datetime(*mytime2[0:6])
            if (dt_obj > dt_obj1) and (dt_obj < dt_obj2):
                t_data[jj] = t_data[jj] + 1
                        
# After data collected:

total_err = 0
for i in t_data:
    total_err = total_err + t_data[i]    

correct_tot = int(total_err / 2.0)
print ">>> Total Errors %s" % correct_tot

for tpl in n_data:
    i = tpl[0]
    mn = tpl[1]
    jj = tpl[2]
    str1 = "%s.%s.%s:%s:%s:%s" % (mytime.tm_year, mytime.tm_mon,
        mytime.tm_mday, i, mn, "00")
    str2 = "%s.%s.%s:%s:%s:%s" % (mytime.tm_year, mytime.tm_mon,
        mytime.tm_mday, i, mn+9, "00")                
    
    mytime1 = time.strptime(str1, "%Y.%m.%d:%H:%M:%S")
    dt_obj1 = datetime(*mytime1[0:6])
    mytime2 = time.strptime(str2, "%Y.%m.%d:%H:%M:%S")
    dt_obj2 = datetime(*mytime2[0:6])
    
    cor_val = int(t_data[jj] / 2.0)
    perc = (cor_val / float(correct_tot)) * 100.0
    print "%s to %s : %s (%.2f %%)" % (dt_obj1, dt_obj2, cor_val, perc)
    
# End of the file #
