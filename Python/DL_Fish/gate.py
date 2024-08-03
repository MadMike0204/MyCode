import numpy as np

class MyGate():

    @staticmethod
    def AND(x1,x2):#与门
        x = np.array([x1,x2])
        w = np.array([0.5,0.5])
        theta = 0.7
        value = np.sum(w*x)
        if(value >= theta):
            return 1
        else:
            return 0
        
    @staticmethod
    def NAND(x1,x2):#非门
        x = np.array([x1,x2])
        w = np.array([-0.5,-0.5])
        theta = -0.7
        value = np.sum(w*x)
        if(value >= theta):
            return 1
        else:
            return 0
    
    @staticmethod
    def OR(x1,x2):#或门
        x = np.array([x1,x2])
        w = np.array([0.5,0.5])
        theta = 0.3
        value = np.sum(w*x)
        if(value >= theta):
            return 1
        else:
            return 0
        
    @staticmethod
    def NOR(x1,x2):#或非门
        x = np.array([x1,x2])
        w = np.array([-0.5,-0.5])
        theta = -0.3
        value = np.sum(w*x)
        if(value >= theta):
            return 1
        else:
            return 0
        
    @staticmethod
    def XOR(x1,x2):#异或门
        value = MyGate.AND(MyGate.NAND(x1,x2),MyGate.OR(x1,x2))
        theta = 0.7
        if(value >= theta):
            return 1
        else:
            return 0

print(MyGate.XOR(1,1))