import numpy as np
import matplotlib.pylab as plt

def f(x):
    return np.sin(x)/x*np.exp(-x)

def sumtrapez(t,n):
    h = t/n
    s = 0
    for i in range (1, n):
        x = i*h
        s += f(x)
    return h/2 * (1 + 2 * s + f(t)) #1 = f(0) stetig fortgestzt

x = np.linspace(1,100)
y = abs(np.pi/4-sumtrapez(x,1000)) #Anzahl der Funktionsauswertungen = 1000
plt.loglog(x,y)
plt.xlabel('T', size='large')
plt.ylabel('Fehler', size='large')
plt.show
plt.savefig('Fehlerplot.png', dpi=400)