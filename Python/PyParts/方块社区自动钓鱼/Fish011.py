import pyautogui
from tkinter import *
from PIL import Image
import tkinter as tk
import keyboard
import time

#设计不同屏幕分辨率相关数值的类 定义成员变量
class ScreenResolution:
    average_pixel = None #相邻判断点偏移距离
    offset_pixel = None #第一个点的偏移距离
    x0 = None #判断框左上角x值
    y0 = None #判断框左上角y值
    deltaX = None #判断框X方向长度
    deltaY = None #判断框Y方向长度
#使用构造方法对成员变量进行赋值
    def __init__(self,average_pixel,offset_pixel,x0,y0,deltaX,deltaY):
        self.average_pixel = average_pixel
        self.offset_pixel = offset_pixel
        self.x0 = x0
        self.y0 = y0
        self.deltaX = deltaX
        self.deltaY = deltaY
        print("ScreenResolution类对象已创建")
        
#创建方法：创建类内部的函数
    def ChangeSR(self,SR):
        print("The screen resolution was changed.")
        
#创建不同分辨率对象 同时赋值
SR_4k = ScreenResolution(67,40,1572,961,672,14)
SR_28k = ScreenResolution(134,70,742,725,1344,22)
SRs = {'1':SR_4k,'2':SR_28k}

#设计群系的类
class Biome:
    NoneSelected_Color = None #无效区间
    Available_Color = None #有效判定区间
    Selected_Color = 230 #选中区间

    def __init__(self,NoneSelected_Color,Available_Color):
        self.NoneSelected_Color = NoneSelected_Color
        self.Available_Color = Available_Color

    def ChangeBiome(self):
        print("The biome was changed.")

#创建群系对象 同时赋值
Biome1 = Biome(107,151)
Biome2 = Biome(78,156)
Biome3 = Biome(78,117)
Biome4 = Biome(151,252)
Biomes = {'1':Biome1,'2':Biome2,'3':Biome3,'4':Biome4}

class LittleUI(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("自动钓鱼v0.4")
        self.geometry("700x550+32+32")
        self.init_UI()

    def init_UI(self):
        self.init_Label()
        self.init_Button()
        self.init_Radiobutton()

    def init_Button(self):
        self.button1 = tk.Button(self,text="开始钓鱼",command=StartFishing,state=NORMAL)
        self.button2 = tk.Button(self,text="停止钓鱼",command=StopFishing,state=DISABLED)
        self.button1.pack()
        self.button2.pack()

    def init_Label(self):
        self.label1 = Label(self,text="点击开始钓鱼",font=("宋体",25),fg="black")
        self.label1.pack()

    def init_Radiobutton(self):
        self.BiomeGroup = tk.StringVar()
        self.BiomeGroup.set('1')
        self.Resolution = tk.StringVar()
        self.Resolution.set('1') 
        self.B_1 = tk.Radiobutton(self,text='海洋群系,蘑菇岛',
                           variable=self.BiomeGroup,value='1',
                           command=self.Select_Biome)
        self.R_4k = tk.Radiobutton(self,text='4k分辨率',
                              variable=self.Resolution,value='1',
                              command=self.Select_Resolution)
        self.B_1.pack()
        self.R_4k.pack()
        
    def Select_Biome(self):
        self.choice = self.BiomeGroup.get()
        self.selected_Biome = Biomes[self.choice]
        self.selected_Biome.ChangeBiome()

    def Select_Resolution(self):
        self.choice = self.Resolution.get()
        self.selected_SR = SRs[self.choice]
        self.selected_SR.ChangeSR(self.selected_SR)

def StartFishing():
    window.button1["state"] = tk.DISABLED
    window.button2["state"] = tk.NORMAL
    print("It has started, man.")
    pyautogui.click(button='right')

def StopFishing():
    window.button1["state"] = tk.NORMAL
    window.button2["state"] = tk.DISABLED
    print("It has stopped,man.")

def Fishing(window):
    screenshot = pyautogui.screenshot(region=(window.selected_SR.x0,
                                              window.selected_SR.y0,
                                              window.selected_SR.deltaX,
                                              window.selected_SR.deltaY))
    screenshot.save('img.png')
    gray_img = screenshot.convert('L')

if __name__ == "__main__":
    window = LittleUI()
    window.mainloop()
