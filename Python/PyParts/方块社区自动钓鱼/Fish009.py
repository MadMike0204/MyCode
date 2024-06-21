import pyautogui
from tkinter import Tk,Label,NORMAL,DISABLED
from PIL import Image
import tkinter
import keyboard
import time

#Throw相关
StateF = False
#初始化是否执行主程序
WhetherToRun = False
#初始化群系灰度值
value_A = 107 #非选中区域
value_B = 151 #判定区域
value_C = 230 #选中区域
#初始化分辨率相关设置
average_pixel = 67
offset_pixel = 40
#初始化左上角坐标
x0 = 1572 #
y0 = 961 #
#长度 
deltaX = 672
deltaY = 14
#自动抛钩
def Throw():

    pyautogui.click(button='right')

#开始钓鱼
def StartFishing():
    button1["state"] = tkinter.DISABLED
    button2["state"] = tkinter.NORMAL
    global WhetherToRun
    WhetherToRun = True
    print("It has started,man.")
    Throw()
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
        
        global StateF
        global value_A
        global value_B
        global value_C
        global average_pixel
        global offset_pixel
        global x0
        global y0
        global deltaX
        global deltaY
        WhetherToGo = True
        StateF = False
        #获取??分辨率窗口最大化下的钓鱼图标
        screenshot = pyautogui.screenshot(region=(x0,y0,deltaX,deltaY))
        #保存图标
        screenshot.save('img.png')
        #打开图标
        image = Image.open('img.png')
        #将图标转换为灰度模式
        gray_img = image.convert('L')
        #找10个点 n代表第几个区域,average_pixel是偏移量,offset_pixel是平均值
        y = 7
        for k in range(10):
            x = k * average_pixel + offset_pixel
            #获取该点处的灰度值
            gray_value = gray_img.getpixel((x,y))
            if gray_value == value_B and WhetherToGo == True:
                WhetherToGo = False
            if gray_value != value_A and gray_value != value_B and gray_value != value_C:
                WhetherToGo = False
        if WhetherToGo == True:
            pyautogui.click(button='right')

            screenshot = pyautogui.screenshot(region=(x0,y0,deltaX,deltaY))
            screenshot.save('img1.png')
            image = Image.open('img1.png')
            gray_img = image.convert('L')
            for k in range(3):
                x = k * average_pixel + offset_pixel
                gray_value = gray_img.getpixel((x,y))
                if StateF == False and gray_value != value_A and gray_value != value_B and gray_value != value_C:
                    time.sleep(1)
                    Throw()
                    StateF = True
    
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

def Screen4k():

    global average_pixel
    global offset_pixel
    global x0
    global y0
    global deltaX
    global deltaY

    average_pixel = 67
    offset_pixel = 40
    x0 = 1572
    y0 = 961
    deltaX = 672
    deltaY = 14

def Screen28k():

    global average_pixel
    global offset_pixel
    global x0
    global y0
    global deltaX
    global deltaY

    average_pixel = 134
    offset_pixel = 70
    x0 = 742
    y0 = 725
    deltaX = 1344
    deltaY = 22

#创建窗口：实例化一个窗口对象。
root = Tk()
#调整窗口位置
root.geometry("700x550+32+32")
#窗口标题
root.title("自动钓鱼v0.3")
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
Resolution = tkinter.StringVar()
Resolution.set('Resolution4k')
#创建群系单选框
oneB = tkinter.Radiobutton(root,text='海洋群系,蘑菇岛',
                           variable=Biome,value='oneB',command=Biome1)
twoB = tkinter.Radiobutton(root,text='普通群系',
                           variable=Biome,value='twoB',command=Biome2)
threeB = tkinter.Radiobutton(root,text='丛林',
                           variable=Biome,value='threeB',command=Biome3)
fourB = tkinter.Radiobutton(root,text='末地',
                           variable=Biome,value='fourB',command=Biome4)
#分辨率单选框
Resolution4k = tkinter.Radiobutton(root,text='4k分辨率',variable =Resolution,
                                   value='Resolution4k',command=Screen4k)
Resolution28k = tkinter.Radiobutton(root,text='2.8k分辨率',variable =Resolution,
                                   value='Resolution28k',command=Screen28k)
#显示单选框
oneB.pack()
twoB.pack()
threeB.pack()
fourB.pack()
Resolution4k.pack()
Resolution28k.pack()
#创建快捷键
keyboard.on_release_key("up",lambda _:StartFishing())
keyboard.on_release_key("down",lambda _:StopFishing())
#显示窗口
root.mainloop()