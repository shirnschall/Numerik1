import numpy as np
import matplotlib.pylab as plt

def f(x):
    return np.sin(x)/x*np.exp(-x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    return h/2*(1+2*sum(fs[1:-1])+fs[-1]) # 1=f(0) stetig fortgesetzt

T=10
errors =[]
hs = 1/2**np.arange(15)
for h in hs:
    errors.append(abs(np.pi/4-sumtrapez(T,h)))
plt.loglog(hs,errors)
plt.loglog(hs,hs**2)
plt.grid(which='major', linewidth=0.5)
plt.xlabel('h', size='large')
plt.ylabel('Fehler', size='large')
plt.show()
plt.savefig('FehlerplotTfix.png', dpi=400)