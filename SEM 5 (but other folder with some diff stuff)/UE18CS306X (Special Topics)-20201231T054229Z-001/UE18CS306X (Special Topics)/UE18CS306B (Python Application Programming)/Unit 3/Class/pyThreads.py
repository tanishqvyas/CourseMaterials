#Multi threading in Python
#orphan thread/process
#Zombie process

#import thread
'''
import threading
import os
import time
#main thread (parent)
#task
#fn (2s)
#fn2 (4s)
def print_cube(num):
	print("cube of a number",num*num*num)
	print("Thread name:",threading.current_thread().name)
	time.sleep(2)
	
def print_square(num):
	print("square of a number",num*num)
	print("Thread name:",threading.current_thread().name)	

if __name__ == "__main__":
	print("ID of the main process",os.getpid())#returns the process id
	print("Main Thread name:",threading.current_thread().name)#returns the thread name
	#count of all active threads
	print("Current thread count",threading.active_count())
	#create a thread
	threading.Thread(target = function_callable, args = tuple_of_argsforfn, name = thread_name)
	t1 = threading.Thread(target = print_cube , args = (10,),name = 't1')
	#start
	t1.start()
	#create a thread
	t2 = threading.Thread(target = print_square , args = (20,), name = 't2')
	#start
	t2.start()
	print("Current thread count",threading.active_count())#returns num of active threads
	#Ensures that parent thread waits till all child threads finish exec
	t1.join()
	t2.join()
	print('Done')
'''
#state of a thread
'''
import threading
import os
import time

def i_am_thread():
	print('Name',threading.current_thread().name)
	#time.sleep(2)

if __name__ == '__main__':
	th = threading.Thread(target = i_am_thread , name = 'groot')
	th.start()
	print("Current thread count",threading.active_count())
	print("State:",th.is_alive())#returns current status of thread(True(if alive)/False)
	th.join()
	print("State:",th.is_alive())
'''
#class: 29/09/2020
#race condition
#1)
'''
x = 20
def f1():
	print(x)
f1()

#2)
x = 20
def f1():
	global x
	x = x+1
	print(x)
f1()
'''
'''
import threading
import time
x = 0
def increment_global():
	global x
	x += 1

def taskOfaThread():
	for _ in range(10000000):
		increment_global()

def main():
	global x
	x = 0
	t1 = threading.Thread(target = taskOfaThread)
	t2 = threading.Thread(target = taskOfaThread)
	t1.start()
	t2.start()
	t1.join()
	t2.join()


if __name__ == '__main__':
	for i in range(10):
		main()
		print(i,x)
'''
'''
import threading
import random
import sys
import time
lock = threading.Lock()
def fn1() :
	s = 'ABCDEFGH'
	for i in range(0, len(s)) :
		lock.acquire()
		print(s[i], end=' ',flush = True)
		time.sleep(int(random.random() * 3))
		print(s[i], end=' ',flush = True)
		lock.release()
		time.sleep(int(random.random() * 3))
			
def fn2() :
	s = 'abcdefgh'
	for i in range(0, len(s)) :
		lock.acquire()
		print(s[i], end=' ',flush = True)
		time.sleep(int(random.random() * 3))
		print(s[i], end=' ',flush = True)
		lock.release()
		time.sleep(int(random.random() * 3))

t1 = threading.Thread(target = fn1)
t2 = threading.Thread(target = fn2)

t1.start()
t2.start()
t1.join()
t2.join()
'''
'''
#import sys
import time
for i in range(10):
	print(i, end = ' ',flush = True)
	#sys.stdout.flush()
	time.sleep(1)

'''
#Class: 01/01/2020
#process#Synchronization
#Semaphore : Bounded and Unbounded
#2 functions prints a message 4times
import threading
from time import sleep
#acquire() and release()
#process
'''
def f1():
	print('f1 starting')
	s1.acquire()#blocking and nonblocking
	for loop in range(1,5):
		print('f1 Working in the Loop')
		sleep(1)
	s1.release()
	print('f1 Exiting')

def f2():
	print('\t\t\tf2 starting')
	while not s1.acquire(blocking = False):
		print('\t\t\tf2: No semaphore available')
		sleep(1)
	else:
		print('\t\t\tf2: Obtained the semaphore')
	for loop in range(1,5):
		print('\t\t\tf2 Working in the Loop')
		sleep(1)
	s1.release()
	print('\t\t\tf2 Exiting')

t1 = threading.Thread(target = f1)
t2 = threading.Thread(target = f2)
t1.start()
t2.start()
t1.join()
t2.join()
print("All threads have completed their Tasks")
'''
#Unbounded Semaphores
s1 = threading.Semaphore(2)#allows 2 processes to acquire the lock
s1.acquire()
print(s1._value)#1
s1.release()
print(s1._value)#2
s1.release()#no error
print(s1._value)

#bounded semaphores: throws an error when you release a lock that was not acquired
s1 = threading.BoundedSemaphore(5)#1
s1.acquire()
print(s1._value)#4
s1.acquire()
print(s1._value)#3
s1.release()
print(s1._value)#4
s1.release()
print(s1._value)#5
try:
	s1.release()
	print(s1._value)#6:throws an error
except ValueError:
	print(“you cannot release a fictional lock”)


















