import requests
import time
import os

def check_internet():
    try:
        # 通过访问一个常见的外网网站来检测是否连通
        response = requests.get("https://www.baidu.com", timeout=5)
        return response.status_code == 200
    except requests.RequestException:
        return False

def login_to_campus_network():
    # 模拟登录过程，以下是一个简单的示例
    # 你需要根据你的校园网登录页面来填写具体的代码
    login_url = "172.30.255.42"
    login_data = {
        "username": "455399",
        "password": "ktq041226"
    }
    
    try:
        session = requests.Session()
        response = session.post(login_url, data=login_data)
        if response.status_code == 200:
            print("成功登录校园网")
        else:
            print("登录失败")
    except requests.RequestException as e:
        print(f"登录过程中出错: {e}")

def main():
    # 每5秒检查一次外网连接状态
    while True:
        if not check_internet():
            print("外网不可用，尝试登录校园网...")
            login_to_campus_network()
        else:
            print("外网连接正常")
        time.sleep(5)

if __name__ == "__main__":
    main()
