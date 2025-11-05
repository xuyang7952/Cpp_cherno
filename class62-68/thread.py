import threading
import time

def task(name):
    print(f"Task {name} started")
    time.sleep(0.1)
    print(f"Task {name} completed")

# 创建并启动多个线程
threads = []
for i in range(5):
    t = threading.Thread(target=task, args=(i,))
    threads.append(t)
    t.start()

# 等待所有线程完成
for t in threads:
    t.join()