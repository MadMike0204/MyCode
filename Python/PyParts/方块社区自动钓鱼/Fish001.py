import pyautogui
from PIL import Image
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

#获取4k分辨率窗口最大化下的钓鱼图标
screenshot = pyautogui.screenshot(region=(742,725,1344,22))
#保存图标
screenshot.save('img.png')
#打开图标
image = Image.open('img.png')
img = cv.imread("img.png")
#将图标转换为灰度模式
gray_img = image.convert('L')
#找几个点 n代表第几个区域,30是偏移量,67.2是平均值
y = 7
for k in range(10):
    x = k * 134 + 70
    #获取该点处的灰度值
    gray_value = gray_img.getpixel((x,y))
    print(gray_value)
    print(f'坐标({x},{y})处的灰度值为:{gray_value}')
    img = cv.circle(img,(x,y),4,(0,0,255),0)
plt.imshow(img)
plt.show()


