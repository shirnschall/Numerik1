library(ggplot2)
require(scales)
require(dplyr)

x <- seq(from=0,to=5,by=0.01)
f <- function(a){
  -(a-5)*(a+5)/5
}
g <- function(a){
  5-1*a
}
h <- function(a){
  sqrt(25-a*a)
}
y<-c(f(x),g(x),h(x))
funktion<-c(rep("-(x-5)(x+5)",times=length(x)), 
          rep("25-5x",times=length(x)),
          rep("h",times=length(x)))

x<-c(x,x,x)

data = data.frame(x,y,funktion)


p <- ggplot(data,aes(x=x,y=y,color=funktion,group=funktion))+
  geom_path(aes(group = funktion)) + 
  theme_bw()+
  xlim(0,5)+
  geom_ribbon(aes(ymin = f(x), ymax = g(x)), fill = "skyblue", alpha = .2)

p

#ggsave("aufgabe-e-vergleich.png", units="in", width=5, height=4, dpi=300)