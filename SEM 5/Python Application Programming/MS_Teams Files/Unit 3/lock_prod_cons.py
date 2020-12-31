#operating systems
#semaphores
'''import threading
from time import sleep
sem=threading.Semaphore()
def func1():
	print("function1 starting")
	sem.acquire()
	for i in range(1,5):
		print("fucntion1 working in loop")
		sleep(1)
	sem.release()
	print("fucntion1 finsished")
def func2():
	print("function2 starting")
	while not sem.acquire(blocking=False):
		print("function2 no semaphore available")
		sleep(1)
	else:
		print("got semaphore")
		for i in range(1,5):
			print("function2 working ")
			sleep(1)
		sem.release()
t1=threading.Thread(target=func1)
t2=threading.Thread(target=func2)
t1.start()
t2.start()
t1.join()
t2.join()
from threading import *
class medicalseat:
	def __init__(self,avail_seat):
		self.avail_seat=avail_seat
		self.lock=BoundedSemaphore(2)
		print(self.lock)
	def reserve_seat(self,need_seat):
		self.lock.acquire()
		#two threads will start simultaneous execution since we gave value as 2
		#once atleast one thread comes out from the code within acquire and release
		#other thread i.e 3rd thread cannot access the piece of code between acquire and release
		print(self.lock._value)
		print('available seats',self.avail_seat)
		if(self.avail_seat>=need_seat):
			name=current_thread().name
			print("seat allocated for",name)
			self.avail_seat-=need_seat
		else:
			print('no more seats')
		self.lock.release()
		#self.lock.release()
		#self.lock.release()
m=medicalseat(2)
t1=Thread(target=m.reserve_seat,args=(1,),name='rama')
t2=Thread(target=m.reserve_seat,args=(1,),name='devi')
t3=Thread(target=m.reserve_seat,args=(1,),name='kavitha')
t1.start()
t2.start()
t3.start()
t1.join()
t2.join()
t3.join()		
'''
'''
string='ABCDEFGH'
string='abcdefgh'

output: aaBBgg

from threading import *
import sys
import time
import random
lock=Lock()
def f1():
        s='ABCDEFGH'
        for i in range(0,len(s)):
                lock.acquire()
                print(s[i],end='')
                sys.stdout.flush()
                time.sleep(int(random.random()*3))
                print(s[i],end='')
                sys.stdout.flush()
                lock.release()
                time.sleep(int(random.random()*3))
def f2():
        s='abcdefgh'
        for i in range(0,len(s)):
                lock.acquire()
                print(s[i],end='')
                sys.stdout.flush()
                time.sleep(int(random.random()*3))
                print(s[i],end='')
                sys.stdout.flush()
                lock.release()
                time.sleep(int(random.random()*3))

t1=Thread(target=f1)
t2=Thread(target=f2)
t1.start()
t2.start()
t1.join()
t2.join()                           
                           

import time
import sys
for i in range(10):
        print(i,end='')
        sys.stdout.flush()
time.sleep(1)

#producer consumer problem
from threading import Thread, Lock, Condition
import time,random
queue=[]
lock=Lock()
#condition object allows one or more threads to wait until notofied by another thread
condition=Condition()#wait and notify
class producer(Thread):
        def run(self):
                nums=range(5)
                global queue
                while True:
                        num=random.choice(nums)
                        lock.acquire()
                        queue.append(num)
                        print('produced',num)
                        lock.release()
                        time.sleep(random.random())
class consumer(Thread):
        def run(self):
                global queue
                while True:
                        lock.acquire()
                        if not queue:
                                print('nothing in queue')
                        num=queue.pop(0)
                        print('consumed',num)
                        lock.release()
                        time.sleep(random.random())

producer().start()
consumer().start()


#condition objects
from threading import Thread, Condition
import time
import random

queue=[]
MAX_NUM=10
condition=Condition()
class ProducerThread(Thread):
        def run(self):
                nums=range(5)
                global queue
                while True:
                        condition.acquire()
                        if len(queue)==MAX_NUM:
                                print("queue is full,producer is waiting")
                                condition.wait()
                                print("space in queue,consumer notified the producer")
                        num=random.choice(nums)
                        queue.append(num)
                        print('produced',num)
                        condition.notify()
                        condition.release()
                        time.sleep(random.random())
class ConsumerThread(Thread):
        def run(self):
                global queue
                while True:
                        condition.acquire()
                        if not queue:
                                print('queue is empty, consumer is waiting')
                                condition.wait()
                                print('producer added something to queue')
                        num=queue.pop(0)
                        print('consumed',num)
                        condition.notify()
                        condition.release()
                        time.sleep(random.random())
ProducerThread().start()
ConsumerThread().start()



import multiprocessing
import time
result=[]
def sq(mylist):
        global result
        for num in mylist:
                result.append(num*num)
        print('result',result)
        time.sleep(1)
if __name__=='__main__':
        mylist=[1,2,3,4,5,6,7,8,9,10]
        p1=multiprocessing.Process(target=sq,args=(mylist,))
        p1.start()
        p1.join()
        print('result',result)

'''
#import threading
import multiprocessing
def sq(mylist,result,square_sum):
        for index,num in enumerate(mylist):
                result[index]=num*num
        square_sum.value=sum(result)
        print('result',result[:])
        print('sum of sqaures',square_sum.value)
if __name__=="__main__":
        mylist=[1,2,3,4,5,6,7,8,9,10]
        result=multiprocessing.Array('i',10)
        square_sum=multiprocessing.Value('i')
        p1=multiprocessing.Process(target=sq,args=(mylist,result,square_sum))
        p1.start()
        p1.join()
        print('main process',result[:])
        print('sum of sqaures',square_sum.value)
                           
        






























