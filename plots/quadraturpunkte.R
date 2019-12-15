library(ggplot2)
require(scales)
require(dplyr)
theme_set(theme_bw())

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-d/quadraturpunkte-n-10",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=Quadraturpunkte,y=Gewichte,group=n))+
  geom_point(size=1) + 
  geom_segment(aes(x=Quadraturpunkte, 
                   xend=Quadraturpunkte, 
                   y=0, 
                   yend=Gewichte)) + 
  labs(title="Lollipop Chart", 
       subtitle="Make Vs Avg. Mileage", 
       caption="source: mpg") 
  theme(axis.text.x = element_text(angle=65, vjust=0.6))

p

ggsave("quadraturpunkte-n-10.png", units="in", width=5, height=4, dpi=300)