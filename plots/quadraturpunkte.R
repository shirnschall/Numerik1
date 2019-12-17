library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-d/quadraturpunkte-n-zusammen",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=Quadraturpunkte,y=Gewichte,color=factor(n),group=factor(n)))+
  geom_point(size=1) + 
  geom_segment(aes(x=Quadraturpunkte, 
                   xend=Quadraturpunkte, 
                   y=0, 
                   yend=Gewichte)) +
  scale_x_continuous(trans="log10")+
  labs(color="n")+
  theme_bw()

p

ggsave("quadraturpunkte-n-zusammen.png", units="in", width=5, height=4, dpi=300)