import numpy as np
import matplotlib.pylab as plt

def step_func(x):
    y = x > 0
    y = y.astype(np.int32)
    return y

def sigmoid(x):
    return 1/(1+np.exp(-x))

# x = np.arange(-5.0,5.0,0.1)
# y = step_func(x)
#y2 = sigmoid(x)
#print(y)
#plt.plot(x,y)
#plt.ylim(-0.1,1.1)
#plt.plot(x,y2)
#plt.show()