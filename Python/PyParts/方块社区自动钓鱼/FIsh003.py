import pyautogui
from tkinter import *
from PIL import Image
import tkinter

WhetherToRun = False

def StartFishing():
    button1["state"] = tkinter.DISABLED
    button2["state"] = tkinter.NORMAL
    global WhetherToRun
    WhetherToRun = True
    print("It has started,man.")
    AutoFish()

def StopFishing():

    global WhetherToRun
    WhetherToRun = False
    button1["state"] = tkinter.NORMAL
    button2["state"] = tkinter.DISABLED
    print("It has stopped,man.")

def AutoFish():

    if WhetherToRun == True:

        WhetherToGo = True
        #获取4k分辨率窗口最大化下的钓鱼图标
        screenshot = pyautogui.screenshot(region=(1572,961,672,14))
        #保存图标
        screenshot.save('img.png')
        #打开图标
        image = Image.open('img.png')
        #将图标转换为灰度模式
        gray_img = image.convert('L')
        #找几个点 n代表第几个区域,30是偏移量,67.2是平均值
        y = 7
        for k in range(10):
            x = k * 67 + 40
            #获取该点处的灰度值
            gray_value = gray_img.getpixel((x,y))
            print(gray_value)
            if gray_value == 151 and WhetherToGo == True:
                WhetherToGo = False
            if gray_value != 107 and gray_value != 151 and gray_value != 230:
                WhetherToGo = False
        if WhetherToGo == True:
            pyautogui.click(button='right')
        root.after(1,AutoFish)

#初始化
#创建窗口：实例化一个窗口对象。
root = Tk()
#调整窗口位置
root.geometry("700x550+3100+1300")
#窗口标题
root.title("自动钓鱼v0.1")
# 添加标签控件
label = Label(root,text="点击开始钓鱼",font=("宋体",25),fg="black")
"""
root:父类窗口对象
text:指定显示的文本
font:指定字体大小和字体样式
fg:指定字体颜色
"""
# 定位
label.pack()
#按钮
button1 = tkinter.Button(root,text="开始钓鱼",command=StartFishing,state=NORMAL)
button2 = tkinter.Button(root,text="停止钓鱼",command=StopFishing,state=DISABLED)
#显示按钮
button1.pack()
button2.pack()
#显示窗口
root.mainloop()