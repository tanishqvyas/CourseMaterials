import multiprocessing
def Square_list(myList,result,square_sum):
	for idx,num in enumerate(myList):
		result[idx] = num*num
	square_sum.value = sum(result)
	print("result in Process p2:",result[:])#1,4,9,16
	print('Sum of squares in process p2:', square_sum.value)#30

if __name__ == "__main__":
	myList = [1,2,3,4]
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
	