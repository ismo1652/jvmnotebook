#
# Simple R plot for data:
#
# '2012-02-01 17:42:44' 
# ...
# Line plot to detect anomalous database queries

library(ggplot2)

req <- read.table("times1.dat")
summary(req)

tt <- req$V1
mytime <- as.POSIXct(tt)

df2 <- data.frame(table(cut(mytime, breaks="30 mins")))
summary(df2)

time <- df2$V1
da   <- df2$V2

png('time_data_errs.png', width=800, height=600)
#gg <- qplot(time, da) + geom_line()


print(gg)
dev.off()
