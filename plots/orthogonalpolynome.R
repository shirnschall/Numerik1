library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-d/orthogonalpolynome",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=x,y=y,color=factor(Grad),group=factor(Grad)))+
  geom_line(size=1) + 
  #scale_x_continuous(trans="log10")+
  labs(color="Grad")+
  theme_bw()

p

#ggsave("quadraturpunkte-n-zusammen.png", units="in", width=5, height=4, dpi=300)