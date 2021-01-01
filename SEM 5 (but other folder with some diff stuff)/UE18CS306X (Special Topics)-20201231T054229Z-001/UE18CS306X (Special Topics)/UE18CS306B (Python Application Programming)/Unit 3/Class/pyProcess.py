#multiprocessing
'''
import multiprocessing
def print_Square(num):
	print('Square of a number is:', num*num)

def print_Cube(num):
	print('Cube of a number is:', num*num*num)

if __name__ == "__main__":
	p1 = multiprocessing.Process(target = print_Square, args = (10,))
	p2 = multiprocessing.Process(target = print_Cube, args = (20,))
	
	#start the process
	p1.start()
	p2.start()
	
	#wait till all processes are complete
	p1.join()
	p2.join()
	
	print("Exiting all processes")

import multiprocessing
import os

def f1():
	print("f1_pid:",os.getpid())

def f2():
	print("f2_pid:",os.getpid())

if __name__ == "__main__":
	#PID of the main process
	print("main_pid: ",os.getpid())
	#creating processes
	p1 = multiprocessing.Process(target = f1)
	p2 = multiprocessing.Process(target = f2)
	#start process
	p1.start()
	p2.start()
	#wait
	p1.join()
	p2.join()
	#end of both processes
	print("Both processes have terminated")
	#status of the processes
	print("p1 status: is alive? ",p1.is_alive())
	print("p2 status: is alive? ",p2.is_alive())
'''
import multiprocessing
import time
result = []
def square_list(myList):
	global result
	for num in myList:
		result.append(num*num)
	print("Result in Process p1: ",result)
	

if __name__ == "__main__":
	myList = [1,2,3,4]	#main P
	#create a process
	p1 = multiprocessing.Process(target = square_list , args = (myList,))
	#start process
	p1.start()
	#wait
	p1.join()
	print("Result in main program:",result)#empty list


import multiprocessing
def Square_list(myList,result,square_sum):
	for idx,num in enumerate(myList):
		result[idx] = num*num
	square_sum.value = sum(result)
	print("result in Process p2:",result[:])#1,4,9,16
	print('Sum of squares in process p2:', square_sum.value)#30

if __name__ == "__main__":
	myList = [1,2,3,4]#myList[:]
	result = multiprocessing.Array('i',4)#d/i
	square_sum = multiprocessing.Value('i')#a=4
	#create process
	p2 = multiprocessing.Process(target = Square_list, args = (myList,result,square_sum))
	#start
	p2.start()
	#wait
	p2.join()
	print('Result in main program:',result[:])
	print('sum of squares in main program:', square_sum.value)








