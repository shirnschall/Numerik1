# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 16:12:23 2019

@author: rafael
"""

import numpy as np
from sympy import symbols, solve, exp
import matplotlib.pylab as plt
from scipy.special import lambertw

def f(x):
    return np.sin(x)/x*np.exp(-x)

def sumtrapez(t,h):
    xs=np.arange(0,t,h)
    fs=f(xs)
    return h/2*(1+2*sum(fs[1:-1])+fs[-1]) # 1=f(0) stetig fortgesetzt

n, t = symbols('n,t')
n = np.arange(1,11,1)
T = []

for i in n:
    T.append((solve(t**3/(12*i**2)-exp(-t),t)))
    print(solve(t**3/(12*i**2)- exp(-t),t))
    
l = [1.424160049, 1.917747325, 2.249717401, 2.503921300, 2.711393902, 2.887378548, 3.040581051, 3.176474208, 3.298736895, 3.409968060]

for i in n:
    print(i)
    print(sumtrapez(l[i-1],l[i-1]/(i)))