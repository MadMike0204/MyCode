import threading
import time
from pynput import mouse, keyboard

# 创建鼠标控制器对象
mouse_controller = mouse.Controller()

# 定义一个全局变量来控制滚轮滚动
scrolling = False

# 定义滚轮滚动的速度（秒），可以调节这个数值控制滚动频率
scroll_speed = 0.5  # 0.1秒滚动一次，调整这个数值来控制速度

# 滚轮滚动的线程函数
def scroll_mouse():
    global scrolling
    while scrolling:
        mouse_controller.scroll(0, -1)  # 向上滚动
        # 如果想要向下滚动，使用 mouse_controller.scroll(0, -2)
        time.sleep(scroll_speed)  # 控制滚动速度

# 键盘监听器回调函数
def on_press(key):
    global scrolling
    try:
        # 当按下 'F8' 键时，启动滚轮滚动
        if key == keyboard.Key.f8 and not scrolling:
            scrolling = True
            # 启动一个新的线程来执行滚轮滚动
            scroll_thread = threading.Thread(target=scroll_mouse)
            scroll_thread.start()

        # 当按下 'F9' 键时，停止滚轮滚动
        elif key == keyboard.Key.f9:
            scrolling = False

    except AttributeError:
        pass

# 开始监听键盘
with keyboard.Listener(on_press=on_press) as listener:
    listener.join()
