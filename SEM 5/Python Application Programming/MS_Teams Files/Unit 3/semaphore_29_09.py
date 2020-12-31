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
t2.join()'''
from threading import *
class medicalseat:
	def __init__(self,avail_seat):
		self.avail_seat=avail_seat
		self.lock=Semaphore(2)
		print(self.lock)
	def reserve_seat(self,need_seat):
		self.lock.acquire()
		print(self.lock._value)
		print('available seats',self.avail_seat)
		if(self.avail_seat>=need_seat):
			name=current_thread().name
			print("seat allocated for",name)
			self.avail_seat-=need_seat
		else:
			print('no more seats')
		self.lock.release()
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
























