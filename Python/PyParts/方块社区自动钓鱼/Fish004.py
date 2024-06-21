import pyautogui
from tkinter import *
from PIL import Image
import tkinter
#初始化是否执行主程序
WhetherToRun = False
#初始化群系灰度值
value_A = 107 #非选中区域
value_B = 151 #判定区域
value_C = 230 #选中区域
#开始钓鱼
def StartFishing():
    button1["state"] = tkinter.DISABLED
    button2["state"] = tkinter.NORMAL
    global WhetherToRun
    WhetherToRun = True
    print("It has started,man.")
    AutoFish()
#停止钓鱼
def StopFishing():

    global WhetherToRun
    WhetherToRun = False
    button1["state"] = tkinter.NORMAL
    button2["state"] = tkinter.DISABLED
    print("It has stopped,man.")
#钓鱼主程序
def AutoFish():

    if WhetherToRun == True:
        
        global value_A
        global value_B
        global value_C
        WhetherToGo = True
        #获取4k分辨率窗口最大化下的钓鱼图标
        screenshot = pyautogui.screenshot(region=(1572,961,672,14))
        #保存图标
        screenshot.save('img.png')
        #打开图标
        image = Image.open('img.png')
        #将图标转换为灰度模式
        gray_img = image.convert('L')
        #找几个点 n代表第几个区域,30是偏移量,67是平均值
        y = 7
        for k in range(10):
            x = k * 67 + 40
            #获取该点处的灰度值
            gray_value = gray_img.getpixel((x,y))
            print(gray_value)
            if gray_value == value_B and WhetherToGo == True:
                WhetherToGo = False
            if gray_value != value_A and gray_value != value_B and gray_value != value_C:
                WhetherToGo = False
        if WhetherToGo == True:
            pyautogui.click(button='right')
        root.after(1,AutoFish)

#作用，不同的群系识别不同的颜色     
def Biome1():

    global value_A
    global value_B
    global value_C
    value_A = 107
    value_B = 151
    value_C = 230

def Biome2():

    global value_A
    global value_B
    global value_C
    value_A = 78
    value_B = 156
    value_C = 230

def Biome3():

    global value_A
    global value_B
    global value_C
    value_A = 78
    value_B = 117
    value_C = 230

def Biome4():

    global value_A
    global value_B
    global value_C
    value_A = 151
    value_B = 252
    value_C = 230
#创建窗口：实例化一个窗口对象。
root = Tk()
#调整窗口位置
root.geometry("700x550+3100+1300")
#窗口标题
root.title("自动钓鱼v0.2")
# 添加标签控件
label = Label(root,text="点击开始钓鱼",font=("宋体",25),fg="black")
# 定位
label.pack()
#按钮
button1 = tkinter.Button(root,text="开始钓鱼",command=StartFishing,state=NORMAL)
button2 = tkinter.Button(root,text="停止钓鱼",command=StopFishing,state=DISABLED)
#显示按钮
button1.pack()
button2.pack()
#单选框
Biome = tkinter.StringVar()
Biome.set('oneB')
#创建群系单选框
oneB = tkinter.Radiobutton(root,text='海洋群系,蘑菇岛',
                           variable=Biome,value='oneB',command=Biome1)
twoB = tkinter.Radiobutton(root,text='普通群系',
                           variable=Biome,value='twoB',command=Biome2)
threeB = tkinter.Radiobutton(root,text='丛林',
                           variable=Biome,value='threeB',command=Biome3)
fourB = tkinter.Radiobutton(root,text='末地',
                           variable=Biome,value='fourB',command=Biome4)
#显示单选框
oneB.pack()
twoB.pack()
threeB.pack()
fourB.pack()
#显示窗口
root.mainloop()