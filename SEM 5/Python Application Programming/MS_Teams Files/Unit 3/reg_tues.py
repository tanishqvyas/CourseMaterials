
#embedding flags in pattern
import time
from threading import *
import threading

class hello(Thread):
    def run(self):
        for i in range(1000):
            print('hello')
            time.sleep(1)
class hi(Thread):
    def run(self):
        for i in range(1000):
            print('hi')
            time.sleep(1)
#t1 = threading.Thread(target= hello)
#t2 = threading.Thread(target= hi)
t1=hello()
t2=hi()
t1.start()
sleep(0.2)
t2.start()
print('bye')
t1.join()
t2.join()





























