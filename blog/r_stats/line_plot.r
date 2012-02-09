# Commands
# Simple line plot with timestamp
# And time

library(ggplot2)

req <- read.table("MeanDiffTime.txt")
summary(req)

da <- req$V1 
db <- req$V2 

png('time_data_errs8b.png', width=640, height=480)
gg <- qplot(da, db) + geom_line()

print(gg)
dev.off()
