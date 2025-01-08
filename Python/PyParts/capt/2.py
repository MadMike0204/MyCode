import pyautogui
import cv2
import numpy as np
import time

# 捕捉屏幕上的特定按钮（返回按钮的中心坐标）
def find_button_on_screen(template_path, confidence=0.8):
    # 截屏
    screenshot = pyautogui.screenshot()
    # 转换为OpenCV格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)

    # 加载模板图像
    template = cv2.imread(template_path, cv2.IMREAD_UNCHANGED)

    # 在屏幕中查找模板图像
    result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)

    # 如果找到的相似度满足要求
    if max_val >= confidence:
        button_x, button_y = max_loc
        button_center = (button_x + template.shape[1] // 2, button_y + template.shape[0] // 2)
        return button_center  # 返回按钮的中心坐标
    else:
        return None  # 未找到

# 主逻辑：点击第一个按钮后等待并点击确认按钮
def click_button_sequence(first_button_path, confirm_button_path, confidence=0.8, wait_time=1):
    while True:  # 循环监控第一个按钮
        # 检测第一个按钮
        first_button_center = find_button_on_screen(first_button_path, confidence)
        if first_button_center:
            print(f"检测到第一个按钮，位置：{first_button_center}")
            pyautogui.moveTo(first_button_center)  # 移动鼠标到第一个按钮
            pyautogui.click()  # 点击第一个按钮

            # 等待一小段时间，等待确认按钮弹出
            print(f"等待 {wait_time} 秒...")
            time.sleep(wait_time)

            # 检测确认按钮
            while True:
                confirm_button_center = find_button_on_screen(confirm_button_path, confidence)
                if confirm_button_center:
                    print(f"检测到确认按钮，位置：{confirm_button_center}")
                    pyautogui.moveTo(confirm_button_center)  # 移动鼠标到确认按钮
                    pyautogui.click()  # 点击确认按钮
                    print("确认按钮已点击！")
                    break  # 跳出确认按钮监控循环

        else:
            print("未检测到第一个按钮，继续监控...")

        # 可选：等待一小段时间后再次检测第一个按钮
        time.sleep(1.5)

# 主程序
if __name__ == "__main__":
    first_button_path = "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\button2.png"  # 第一个按钮的模板图像路径
    confirm_button_path = "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\button1.png"  # 确认按钮的模板图像路径
    click_button_sequence(first_button_path, confirm_button_path, confidence=0.8, wait_time=0.7)
