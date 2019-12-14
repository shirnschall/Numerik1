# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 14:33:15 2019

@author: rafael
"""

import numpy as np
from sympy import symbols, solve, exp
import matplotlib.pylab as plt

n, t = symbols('n,t')
n = 2**np.arange(8)
T = []

for i in n:
    T.append((solve(t**3/(12*i**2)- exp(-t),t)))

plt.plot(n,T)
plt.grid(which='major', linewidth=0.5)
plt.xlabel('n', size='large')
plt.ylabel('T', size='large')
plt.show