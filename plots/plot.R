library(ggplot2)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-d/sinx",header = TRUE ,sep = "\t")

ggplot(data,aes(x=x,y=y,color=funktion))+
  geom_line(size=0.75)
