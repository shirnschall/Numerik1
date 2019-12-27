import numpy as np
import matplotlib.pylab as plt

def f(x):
    return 1/(np.exp(x)+7)*np.exp(-x)

def g(x):
    return 1/(np.exp(x)+7)*np.exp(-x*x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    return h/2*(fs[0]+2*sum(fs[1:-1])+fs[-1])

def sumtrapez2(t,h):
    xs=np.arange(0,t,h)
    fs=g(xs)
    return h/2*(fs[0]+2*sum(fs[1:-1])+fs[-1])

h=0.001
errors =[]
errors2 = []
T = 2**np.arange(12)
for t in T:
    errors.append(abs(1/49*(7-np.log(8))-sumtrapez(t,h)))
    errors2.append(abs(0.10014655923-sumtrapez2(t,h)))
fig = plt.figure()
ax = plt.subplot(111)
ax.loglog(T,errors, label = '1/(exp(x)+7)*exp(-x)')
ax.loglog(T,errors2, 'r--', label = '1/(exp(x)+7)*exp(-x*x)')
ax.grid(which='major', linewidth=0.5)
ax.set_xlabel('T', size='large')
ax.set_ylabel('Fehler', size='large')
#chartBox = ax.get_position()
#ax.set_position([chartBox.x0, chartBox.y0, chartBox.width*0.6, chartBox.height])
#ax.legend(loc='upper center', bbox_to_anchor=(1.45, 0.8), shadow=True, ncol=1)
ax.legend()
plt.show()
#plt.savefig('Fehlerploth.png', dpi=400)