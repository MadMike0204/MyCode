import numpy as np
import matplotlib.pyplot as plt

class ReLU:
    def __init__(self):
        self.mask = None

    def forward(self,x):
        self.mask = (x <= 0)
        out = x.copy()
        out[self.mask] = 0
        return out
    
    def backward(self,dout):
        dout[self.mask] = 0
        dx = dout
        return dx

class Sigmoid:
    def __init__(self):
        self.x = None
    
    def forward(self,x):
        out = 1/(1+np.exp(-x))
        return out
    
    def backward(self,dout):
        dx = dout * (1.0 - self.out) * self.out
        return dx
    
class Affine:
    def __init__(self,W,b):
        self.W = W
        self.b = b
        self.x = None
        self.db = None
        self.dW = None
    
    def forward(self,x):
        self.x = x
        out = np.dot(x,self.W) + self.b
        return out
    
    def backward(self,dout):
        dx = np.dot(dout,self.W.T)
        self.dW = np.dot(self.x.T,dout)
        self.db = np.sum(dout,axis=0)
        return dx

class Softmax:
    pass

#    
X = np.array([-1,2,-3,5])
#
ReLU_layer = ReLU()
# forward
Y = ReLU_layer.forward(X)
print(Y)
# backward
dX = ReLU_layer.backward(Y)
print(dX)