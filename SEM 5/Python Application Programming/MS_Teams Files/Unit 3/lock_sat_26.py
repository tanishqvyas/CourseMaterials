#operating systems
#mutliprocessing/multithreading
#locks

import time
from multiprocessing import Process, Lock, Value
#no multiprocessing
'''
def deposit(total):
	for i in range(100):
		time.sleep(0.01)
		total+=5
	return total
def withdraw(total):
	for i in range(100):
		time.sleep(0.01)
		total-=5
	return total
'''
'''
#mp
def deposit(total):
	for i in range(100):
		time.sleep(0.01)
		total.value+=5
def withdraw(total):
	for i in range(100):
		time.sleep(0.01)
		total.value-=5
'''
#multi processing with locks
def deposit(total):
	for i in range(100):
		time.sleep(0.01)
		lock.acquire()
		total.value+=5
		lock.release()
def withdraw(total):
	for i in range(100):
		time.sleep(0.01)
		lock.acquire()
		total.value-=5
		lock.release()
		
if __name__=='__main__':
	'''total=500
	print(total)
	total=deposit(total)
	print(total)
	total=withdraw(total)
	print(total)
	total=Value('i',500)
	deposit_proc=Process(target=deposit,args=(total,))
	withdraw_proc=Process(target=withdraw,args=(total,))
	deposit_proc.start()
	withdraw_proc.start()
	deposit_proc.join()
	withdraw_proc.join()
	print(total.value)'''
	total=Value('i',500)
	lock=Lock()
	deposit_proc=Process(target=deposit,args=(total,))
	withdraw_proc=Process(target=withdraw,args=(total,))
	deposit_proc.start()
	withdraw_proc.start()
	deposit_proc.join()
	withdraw_proc.join()
	print(total.value)


