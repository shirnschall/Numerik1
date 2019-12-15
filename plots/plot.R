library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-d/aufgabe-e",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=Quadraturpunkte,y=Fehler,color=Funktion,group=Funktion))+
  geom_point() + geom_path(aes(group = Funktion))

p

ggsave("aufgabe-e.png", units="in", width=5, height=4, dpi=300)