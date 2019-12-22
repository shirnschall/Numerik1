# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 14:33:15 2019

@author: rafael
"""

import numpy as np
from sympy import symbols, solve, exp
import matplotlib.pylab as plt


def f(x):
    return np.sin(x)/x*np.exp(-x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    return h/2*(1+2*sum(fs[1:-1])+fs[-1]) # 1=f(0) stetig fortgesetzt

n, t = symbols('n,t')
T = np.arange(1,50)
h = []

for i in T:
    h.append(np.sqrt(12*np.exp(-i)/i))
    
print(h)
#h=[]
#for i in n:
#    h.append((solve(t*i**2/(12)- exp(-t),t)))

n = []
for i in T:
    n.append(i/h[i-1])

#print(n)

error = []
for i in T:
    error.append(abs(np.pi/4-sumtrapez(i,h[i-1])))

print(error)
plt.loglog(n,error)
#plt.loglog(n,h)
plt.grid(which='major', linewidth=0.5)
plt.xlabel('n', size='large')
plt.ylabel('Fehler', size='large')
plt.show