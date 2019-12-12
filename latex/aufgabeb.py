import numpy as np
import matplotlib.pylab as plt

def f(x):
    return np.sin(x)/x*np.exp(-x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    s=2*sum(fs[1:-1])+1+fs[-1]
    #for i in range (1, len(n)):
    #    x = i*h
    #    s += f(x)
    #return h/2 * (f(0) + 2 * s + f(t)) #1 = f(0) stetig fortgestzt
    return h/2*s

print(sumtrapez(10,0.001))
T=10
#jetzt t fix, fktaus varrieren, label stimmt nicht
errors =[]
hs = 1/2**np.arange(15)
for h in hs:
    errors.append(abs(np.pi/4-sumtrapez(T,h)))
plt.loglog(hs,errors)
plt.loglog(hs,hs**2)
plt.grid(which='major', linewidth=0.5)
plt.show()

#y = abs(1/2-sumtrapez(1000,x)) #Anzahl der Funktionsauswertungen = 1000
#plt.loglog(x,y)
#plt.xlabel('T', size='large')
#plt.ylabel('Fehler', size='large')
#plt.grid(which='both', linewidth=0.5)
#plt.show
#plt.savefig('Fehlerplot.png', dpi=400)
#print(min(abs(np.pi/4-sumtrapez(1000,x))))