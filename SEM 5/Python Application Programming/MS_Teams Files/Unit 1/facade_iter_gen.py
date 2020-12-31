'''import time
class tc1:
	def run(self):
		print(".... in test1.....")
		time.sleep(1)
		print("setting tp")
		time.sleep(1)
		print("running test")
		time.sleep(1)
		print("test finsihed")
class tc2:
	def run(self):
		print(".... in test2.....")
		time.sleep(1)
		print("setting tp")
		time.sleep(1)
		print("running test")
		time.sleep(1)
		print("test finsihed")
class tc3:
	def run(self):
		print(".... in test3.....")
		time.sleep(1)
		print("setting tp")
		time.sleep(1)
		print("running test")
		time.sleep(1)
		print("test finsihed")
#facade
class testrunner:
	def __init__(self):
		self.Tc1=tc1()
		self.Tc2=tc2()
		self.Tc3=tc3()
	def runall(self):
		self.Tc1.run()
		self.Tc2.run()
		self.Tc3.run()
if __name__=='__main__':
	Testrunner=testrunner()
	Testrunner.runall()
'''
'''
nums=[10,20,30]
i_nums=nums.__iter__()  #i_nums=iter(nums)
print(i_nums)
print(dir(i_nums))
print(next(i_nums))
print(next(i_nums))
print(next(i_nums))
print(next(i_nums))

'''
'''
class tophundred:
	def __init__(self):
		self.num=1
	def __iter__(self):
		return self
	def __next__(self):
		if self.num<=100:
			value=self.num
			self.num+=1
			return value
		else:
			raise StopIteration
val=tophundred()
for i in val:
	print(i)

'''
def my_gen():
	n=1
	print("this is printed first")
	yield n
	n+=1
	print("this is printed second") 
	yield n
	n+=1
	print("this is printed last")
	yield n
a=my_gen()

for i in a:
	print(i)	
