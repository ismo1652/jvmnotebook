# Simple R plot for data  
# '2012-02-01 17:42:44'   
# Line plot to detect anomalous database queries 
# Run with: 
# r CMD BATCH /home/src/jvmnotebook/java/scripting/line_plot2.r 
 
library(ggplot2) 
 
req <- read.table("times1.dat") 
summary(req) 
 
tt <- req$V1 
MyDates <- as.POSIXct(tt) 
# Break by 30 min intervals and add-in frequency 
MyDatesTable <- table(cut(MyDates, breaks="60 mins")) 
MyDatesDF <- data.frame(MyDatesTable, grp = 1) 
 
png('time_data_errs2.png', width=800, height=600) 
gg <- ggplot(MyDatesDF, aes(Var1, Freq)) + geom_line(aes(group = grp))  
print(gg) 
dev.off() 

