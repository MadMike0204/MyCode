import pyautogui
import cv2
import numpy as np
import time

# 捕捉屏幕上的特定按钮（返回所有匹配位置）
def find_all_buttons_on_screen(template_path, confidence=0.8):
    # 截屏
    screenshot = pyautogui.screenshot()
    # 转换为OpenCV格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)

    # 加载模板图像
    template = cv2.imread(template_path, cv2.IMREAD_UNCHANGED)

    # 在屏幕中查找模板图像
    result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED)
    locations = np.where(result >= confidence)  # 找到所有匹配的位置

    # 保存所有按钮中心点
    buttons = []
    for (x, y) in zip(locations[1], locations[0]):
        button_center = (x + template.shape[1] // 2, y + template.shape[0] // 2)
        buttons.append(button_center)
    
    return buttons

# 自动点击所有匹配的按钮
def click_all_buttons(template_path, confidence=0.9):
    buttons = find_all_buttons_on_screen(template_path, confidence)
    if buttons:
        for i, button_center in enumerate(buttons):
            time.sleep(1)
            print(f"第{i+1}个按钮位置：{button_center}")
            pyautogui.moveTo(button_center)  # 移动鼠标到按钮位置
            pyautogui.click()  # 点击按钮
    else:
        print("未找到按钮！")

# 主程序
if __name__ == "__main__":
    # 按钮模板图片路径列表（多个按钮）
    template_paths = ["F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\button1.png",
                      "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\button2.png"]  # 替换为你的按钮图片路径

    # 遍历每个按钮模板，依次点击
    for template_path in template_paths:
        print(f"开始查找并点击模板：{template_path}")
        
        click_all_buttons(template_path, confidence=0.8)
