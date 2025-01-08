import pyautogui
import cv2
import numpy as np
import time

# 捕捉屏幕上的特定按钮（返回所有匹配的位置）
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

# 点击特定按钮的逻辑
def click_button(button_center):
    pyautogui.moveTo(button_center)  # 移动鼠标到按钮位置
    pyautogui.click()  # 点击按钮
    time.sleep(0.9)  # 短暂停留

# 主逻辑：点击批改按钮后等待并点击弹出按钮
def handle_correction_button(confirm_button_path, done_button_path, confidence=0.8, wait_time=1):
    # 等待确认按钮弹出
    while True:
        confirm_button_center = find_button_on_screen(confirm_button_path, confidence)
        if confirm_button_center:
            print(f"检测到确认按钮，位置：{confirm_button_center}")
            click_button(confirm_button_center)  # 点击确认按钮
            break
        time.sleep(0.9)  # 等待

    # 等待“完成”按钮弹出
    while True:
        done_button_center = find_button_on_screen(done_button_path, confidence)
        if done_button_center:
            print(f"检测到完成按钮，位置：{done_button_center}")
            click_button(done_button_center)  # 点击完成按钮
            print("完成按钮已点击！")
            break
        time.sleep(0.9)  # 等待

# 捕捉屏幕上的单个按钮（返回按钮的中心坐标）
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

# 主程序
if __name__ == "__main__":
    # 模板图像路径
    correction_button_path = "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\piyue.png"  # 批改按钮模板路径
    confirm_button_path = "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\button1.png"  # 确认按钮模板路径
    done_button_path = "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\button2.png"  # 完成按钮模板路径

    # 查找所有“批改”按钮
    correction_buttons = find_all_buttons_on_screen(correction_button_path, confidence=0.8)
    print(f"检测到 {len(correction_buttons)} 个批改按钮")

    # 依次点击每个批改按钮，并处理弹出操作
    for i, correction_button in enumerate(correction_buttons):
        print(f"开始处理第 {i+1} 个批改按钮，位置：{correction_button}")
        click_button(correction_button)  # 点击当前批改按钮

        # 处理确认和完成按钮
        handle_correction_button(confirm_button_path, done_button_path, confidence=0.8, wait_time=1)

    print("所有批改按钮处理完毕！")
