import pyautogui
import cv2
import numpy as np
import time

# 捕捉屏幕上的多个按钮（返回所有匹配位置）
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

# 点击特定按钮
def click_button(button_center):
    pyautogui.moveTo(button_center)  # 移动鼠标到按钮位置
    pyautogui.click()  # 点击按钮
    time.sleep(0.5)  # 稍作等待，防止误操作

# 点击批阅按钮并完成操作
def process_single_correction(correction_button, mark_as_reviewed_path, confirm_button_path, confidence=0.8, wait_time=2):
    # 点击“批阅”按钮
    print(f"点击批阅按钮：{correction_button}")
    click_button(correction_button)

    # 等待加载完成
    print(f"等待 {wait_time} 秒...")
    time.sleep(wait_time)

    # 点击“标记为已批阅”按钮
    while True:
        mark_as_reviewed_button = find_button_on_screen(mark_as_reviewed_path, confidence)
        if mark_as_reviewed_button:
            print(f"检测到标记为已批阅按钮：{mark_as_reviewed_button}")
            click_button(mark_as_reviewed_button)
            break
        time.sleep(0.5)  # 如果未检测到，继续等待

    # 等待加载完成
    print(f"等待 {wait_time} 秒...")
    time.sleep(wait_time)

    # 点击“确定”按钮
    while True:
        confirm_button = find_button_on_screen(confirm_button_path, confidence)
        if confirm_button:
            print(f"检测到确定按钮：{confirm_button}")
            click_button(confirm_button)
            break
        time.sleep(0.5)  # 如果未检测到，继续等待

    print("完成一次批阅流程！返回批阅界面。")

# 捕捉屏幕上的单个按钮（返回按钮的中心坐标）
def find_button_on_screen(template_path, confidence=0.95):
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

def filter_duplicate_buttons(buttons, threshold=10):
    """
    过滤掉位置非常接近的按钮，避免重复检测。
    :param buttons: 按钮坐标列表 [(x1, y1), (x2, y2), ...]
    :param threshold: 距离阈值，两个按钮的距离小于此值时视为重复
    :return: 去重后的按钮列表
    """
    filtered_buttons = []
    for button in buttons:
        # 检查当前按钮是否与已保存的按钮过于接近
        if all(abs(button[0] - b[0]) > threshold or abs(button[1] - b[1]) > threshold for b in filtered_buttons):
            filtered_buttons.append(button)
    return filtered_buttons


# 主程序
if __name__ == "__main__":
    # 模板图像路径
    path = "F:\\------------------OWN\\VSCode\\Python\\PyParts\\capt\\"
    correction_button_path = path + "piyue.png"  # 批阅按钮模板路径
    mark_as_reviewed_path = path + "bj.png"  # 标记为已批阅按钮模板路径
    confirm_button_path = path + "cf.png"  # 确定按钮模板路径

    # 查找所有“批阅”按钮

    correction_buttons = find_all_buttons_on_screen(correction_button_path, confidence=0.8)
    correction_buttons = filter_duplicate_buttons(correction_buttons, threshold=15)
    if correction_buttons:
        print(f"检测到 {len(correction_buttons)} 个批阅按钮")
        for i, correction_button in enumerate(correction_buttons):
            print(f"开始处理第 {i+1} 个批阅按钮，位置：{correction_button}")
            process_single_correction(correction_button, mark_as_reviewed_path, confirm_button_path, confidence=0.8, wait_time=1)
    else:
        print("未检测到批阅按钮，继续监控...")
    time.sleep(1)  # 等待一会儿后重新检测
