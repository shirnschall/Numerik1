library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-e/f-vergleich-integral",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=T,y=Integral.T.bis.Unendlich,color=Funktion,group=Funktion))+
  geom_line() + 
  theme_bw() +
  scale_y_log10()

p

ggsave("aufgabe-e-vergleich-integral.png", units="in", width=5, height=4, dpi=300)