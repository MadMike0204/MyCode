from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
import time
import time
import requests

def login_to_campus_network():
    # 设置浏览器驱动路径（请根据你系统的实际路径修改）
    driver_path = "D:/ChromeDriver132/chromedriver.exe"
    service = Service(driver_path)
    
    # 启动浏览器
    driver = webdriver.Chrome(service=service)
    
    # 打开校园网登录页面http://172.30.255.42/
    login_url = "http://172.30.255.42/"  # 这里替换成你的登录页面URL
    driver.get(login_url)
    
    # 找到并填写账号和密码字段
    # username_field = driver.find_element(By.XPATH, "//*[@id='edit_body']/div[3]/div[1]/div/div[2]/div[1]/div/form/input[3]")  
    username_field = WebDriverWait(driver, 10).until(
    EC.element_to_be_clickable((By.XPATH, "//*[@id='edit_body']/div[3]/div[1]/div/div[2]/div[1]/div/form/input[3]"))
)
    
    password_field = driver.find_element(By.XPATH, "//*[@id='edit_body']/div[3]/div[1]/div/div[2]/div[1]/div/form/input[4]")  
    
    # 输入账号和密码
    username_field.send_keys("-")  # 输入你的账号
    password_field.send_keys("-")  # 输入你的密码
    
    # 找到并勾选同意免责条款和记住密码选项
    agreement_checkbox = driver.find_element(By.NAME, "C1")  # 根据checkbox的name属性定位
    remember_checkbox = driver.find_element(By.NAME, "savePassword")  # 根据checkbox的name属性定位
    
    # 勾选这些选框
    if not agreement_checkbox.is_selected():
        agreement_checkbox.click()
    
    if not remember_checkbox.is_selected():
        remember_checkbox.click()
    
    # 提交登录表单
    login_button = driver.find_element(By.XPATH, "//*[@id='edit_body']/div[3]/div[1]/div/div[2]/div[1]/div/form/input[2]")  # 根据登录按钮的name属性定位
    login_button.click()
    
    # 你可以在这里添加一些验证是否登录成功的逻辑，检查页面上的元素
    # 比如查找“登出”按钮来确认是否登录成功
    try:
        if(check_internet()):
            print("登录成功")
    except:
        print("登录失败")
    
    # 关闭浏览器
    driver.quit()

def check_internet():
    try:
        # 通过访问一个常见的外网网站来检测是否连通
        response = requests.get("https://www.baidu.com", timeout=1.2)
        return response.status_code == 200
    except requests.RequestException:
        return False

def main():
    # 每5秒检查一次外网连接状态
    while True:
        if not check_internet():
            print("外网不可用，尝试登录校园网...")
            print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))
            login_to_campus_network()
        else:
            print("外网连接正常")
            print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))
        time.sleep(3)

if __name__ == "__main__":
    main()
