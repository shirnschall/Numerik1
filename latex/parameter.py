# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 14:33:15 2019

@author: rafael
"""

import numpy as np
from sympy import symbols, solve, exp
import matplotlib.pylab as plt

n, t = symbols('n,t')
n = 2**np.arange(10)
T = []

for i in n:
    T.append((solve(t**3/(12*i**2)- exp(-t),t)))
    
h=[]
for i in n:
    h.append((solve(t*i**2/(12)- exp(-t),t)))

plt.loglog(n,T)
plt.loglog(n,h)
plt.grid(which='major', linewidth=0.5)
plt.xlabel('n', size='large')
plt.legend('Th')
plt.show