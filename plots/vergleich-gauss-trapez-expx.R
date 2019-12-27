library(ggplot2)
require(scales)
require(dplyr)

data=read.csv("/Users/shirnschall/Desktop/Numerik1/code/aufgabe-e/vergleich-gauss-trapez-expx",header = TRUE ,sep = "\t")

p <- ggplot(data,aes(x=Quadraturpunkte,y=Fehler,color=Funktion,group=Funktion))+
  geom_line(aes(linetype =Funktion)) + 
  theme_bw() +
  #scale_y_continuous(trans="log10",labels = scales::trans_format("log10", scales::math_format(10^.x)))+
  theme(
    legend.position = c(.97, .97),
    legend.justification = c("right", "top"),
    legend.box.just = "right",
    legend.margin = margin(6, 6, 6, 6)
  )+
  labs(color = "Quadraturformel",group="Quadraturformel",linetype="Quadraturformel")+
  geom_hline(yintercept=10e-17, linetype="dashed", color="darkgray",size=0.5,group="test") +
  scale_y_log10(
    breaks =  sort(c(10e-2,10e-6,10e-10,10e-14,10e-17)),
    labels = scales::trans_format("log10", scales::math_format(10^.x))
  )

p

ggsave("vergleich-gauss-trapez-expx.png", units="in", width=5, height=4, dpi=300)