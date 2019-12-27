library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe_b/c/vergleich-gewichtsfnkt",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=Quadraturpunkte,y=Fehler,color=Gewichtsfunktion,group=Gewichtsfunktion))+
  geom_line(aes(linetype =Gewichtsfunktion)) + 
  theme_bw() +
  scale_y_continuous(trans="log10",labels = scales::trans_format("log10", scales::math_format(10^.x)))+
   theme(
    legend.position = c(.95, .95),
    legend.justification = c("right", "top"),
    legend.box.just = "right",
    legend.margin = margin(6, 6, 6, 6)
  )

p

ggsave("aufgabe-e-vergleich-trapez-gewichtsfnkt.png", units="in", width=5, height=4, dpi=300)