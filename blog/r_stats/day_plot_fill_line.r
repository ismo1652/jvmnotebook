# Commands
# Plot by day and a simple count

library(ggplot2)

req <- read.table("all_day.txt")

summary(req)

dy <- as.Date(req$V1)

summary(dy)

png('time_data_day.png', width=640, height=480)
gg <- qplot(dy, req$V2, file=I("steelblue1")) + 
          geom_line(size=2) + geom_area(colour='green', fill='mediumpurple1') +
        geom_point(shape=3, size=4) +
        xlab("Day of Errors") +
        ylab("Count of Errors") +
        opts(title="Daily Errors")
        
print(gg)
dev.off()
