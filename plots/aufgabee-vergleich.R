library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-e/f-vergleich",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=x,y=y,color=Funktion,group=Funktion))+
  geom_line(aes(linetype =Funktion)) + 
  theme_bw()

p

ggsave("aufgabe-e-vergleich.png", units="in", width=5, height=4, dpi=300)