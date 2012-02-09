#
# Simple R plot for data:
#
# 'T4618' 'TOxIFKxwXH-gdkUZZb0rbqB' 106451 -0.0	152	1	'2012-02-01 17:42:44'	'launch/'
# ...
# Line plot to detect time between clicks for user.

library(ggplot2)

req <- read.table("good_user.txt")
summary(req)

da <- req$V4 
db <- req$V7 

time <- as.POSIXct(db)

png('time_data_errs9b.png', width=640, height=480)
gg <- qplot(time, da) + geom_line()

print(gg)
dev.off()
