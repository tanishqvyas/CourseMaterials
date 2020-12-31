#24-09-2020
#operating systems
#threads
'''import threading
from threading import *
import time
class task1(Thread):
    def run(self):
        for i in range(5):
            print("task1")
            time.sleep(1)
class task2(Thread):
    def run(self):
        for i in range(5):
            print("task2")
            time.sleep(1)
t1=task1()
t2=task2()
t1.start()
time.sleep(0.2)
t2.start()
print('current thread count',threading.active_count())
print("state t1",t1.is_alive())
print("state t2",t1.is_alive())
# please wait until
t1.join()
print("state t1",t1.is_alive())
t2.join()
print("state t2",t1.is_alive())
print("completed")
'''
'''import threading
from threading import Thread
def i_am_thread():
    print("i am thread")
th=Thread(target=i_am_thread,name='rrr')
th.start()
print("current count",threading.active_count())
print('state',th.is_alive())
th.join()
print('state',th.is_alive())
print('get name',th.getName())
print("main thread:",threading.main_thread().name)

'''
import threading
def print_cube(num):
    print('cube of a number',num*num*num)
def print_square(num):
    print('square of a number',num*num)
t1=threading.Thread(target=print_cube,args=(10,))
t2=threading.Thread(target=print_square,args=(10,))
t1.start()#internally run method is called
t2.start()
t1.join()
t2.join()
print("done")






