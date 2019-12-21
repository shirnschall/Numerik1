library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-d/aufgabe-e-exp-xx",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=Quadraturpunkte,y=Fehler,color=Funktion,group=Funktion))+
  geom_point(aes(shape = Funktion)) + 
  geom_path(aes(group = Funktion))+
  theme_bw()+
  geom_hline(yintercept=10e-17, linetype="dashed", color="darkgray",size=0.5,group="test") +
  scale_y_log10(
    breaks =  sort(c(10e-2,10e-6,10e-10,10e-14,10e-17)),
    labels = scales::trans_format("log10", scales::math_format(10^.x))
  )
  
p

ggsave("aufgabe-e2-e-xx.png", units="in", width=5, height=4, dpi=300)