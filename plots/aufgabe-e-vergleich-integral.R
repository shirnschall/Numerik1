library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-e/f-vergleich-integral",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=T,y=Integral.T.bis.Unendlich,color=Funktion,group=Funktion))+
  geom_line(aes(linetype =Funktion)) + 
  theme_bw() +
  scale_y_continuous(trans="log10",labels = scales::trans_format("log10", scales::math_format(10^.x)))
  #geom_hline(yintercept=10e-17, linetype="dashed", color="darkgray",size=0.5,group="test") +
  #scale_y_log10(
  #  breaks =  sort(c(10e-2,10e-6,10e-10,10e-14,10e-17)),
  #  labels = scales::trans_format("log10", scales::math_format(10^.x))
  #)
  
p

ggsave("aufgabe-e-vergleich-integral.png", units="in", width=5, height=4, dpi=300)