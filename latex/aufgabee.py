# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 16:12:23 2019

@author: rafael
"""

import numpy as np
from sympy import symbols, solve, exp
from scipy.optimize import fsolve
import matplotlib.pylab as plt
from scipy.special import lambertw

def f(x):
    return np.exp(-x*x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    return h/2*(fs[0]+2*sum(fs[1:-1])+fs[-1]) # 1=f(0) stetig fortgesetzt

n, t = symbols('n,t')

T = 5

h  = []
#w = []
n = np.arange(1,50,1)
a = []

#for i in n:
#    for j in np.arange(1,100):
#        w = []
#        w.append(j**3/(12*i**2)-np.exp(-j)) 
        #a.append(j)  
        #print(min(w))
    #print(i,a[i-1])
        
print(2)
for i in n:
    h.append(T/i)

#print(h)

#for i in range(1,50):
 #   print(i, abs(0.10042-sumtrapez(h[i-1]*i,h[i-1])))

#plt.loglog(n,h)
#plt.show
T = []

for i in n:
    T.append((solve(t**3/(12*i**2)-exp(-t),t)))
    #print(solve(t**3/(12*i**2)- exp(-t),t))

#print(T) 
l = [1.424160049, 1.917747325, 2.249717401, 2.503921300, 2.711393902, 2.887378548, 3.040581051, 3.176474208, 3.298736895, 3.409968060, 3.512075595, 3.606503619, 3.694372896, 3.776571525, 3.853815759, 3.926692041, 3.995686857, 4.061208441, 4.123602840, 4.183166040, 4.240153272, 4.294786218, 4.347258696, 4.397741184, 4.446384450, 4.493322507, 4.538675013, 4.582549296, 4.625041971, 4.666240359, 4.706223630, 4.745063814, 4.782826626, 4.819572195, 4.855355688, 4.890227841, 4.924235421, 4.957421643, 4.989826515, 5.021487153, 5.052438054, 5.082711342, 5.112336978, 5.141342955, 5.169755463, 5.197599048, 5.224896744, 5.251670196, 5.277939768]

#print(sumtrapez(l[3],0.001))
for i in n:
    print(i, abs(0.886227-sumtrapez(l[i-1],l[i-1]/i)))