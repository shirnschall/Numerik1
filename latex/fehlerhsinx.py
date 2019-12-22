import numpy as np
import matplotlib.pylab as plt

def f(x):
    return 1/(np.exp(x)+7)*np.exp(-x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    return h/2*(fs[0]+2*sum(fs[1:-1])+fs[-1])

h=0.001
errors =[]
T = 2**np.arange(12)
for t in T:
    errors.append(abs(0.10042-sumtrapez(t,h)))
plt.loglog(T,errors)
plt.grid(which='major', linewidth=0.5)
plt.xlabel('T', size='large')
plt.ylabel('Fehler', size='large')
plt.show()
plt.savefig('Fehlerploth.png', dpi=400)