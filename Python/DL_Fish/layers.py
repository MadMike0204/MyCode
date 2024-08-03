import numpy as np
import matplotlib.pylab as plt
import sigmoid

def layer_1(X):
    # 2输入 3输出
    W = np.array([[0.3,0.1,0.3],[0.1,0.3,0.1]],dtype=float)
    B = np.array([0.6,7.2,4.0],dtype=float)
    return np.dot(X,W)+B

X = np.array([2.2,1.8],dtype=float)
print("Original input:")
print(X)
W = np.array([[0.3,0.6,0.9],[0.1,0.7,0.4]],dtype=float)
print("Weight:")
print(W)
Y = layer_1(X)
print("Layer_1 output:")
print(Y)
Z = sigmoid.sigmoid(Y)
print("Layer_1 after sigmoid:")
print(Z)

plt.plot(X,Z)
plt.ylim(-0.1,1.1)
plt.show()


