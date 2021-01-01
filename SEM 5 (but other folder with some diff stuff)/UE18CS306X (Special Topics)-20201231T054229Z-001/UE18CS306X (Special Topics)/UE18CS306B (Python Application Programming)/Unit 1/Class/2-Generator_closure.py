#generators:functions that generate values on demand
#yield : makes this a lazy function
#generators => iterator => access the values of the generator
def f1():
	return 1
	return 2#not reachable
	return 3#not reachable

#print(f1())

def f2():
	yield 1#2. pause
	print("after 1st yield")
	yield 2#4. pause
	yield 3#6.pause
'''
print(f2())
g = f2()#1. play
#next(g)#3. resume
#next(g)#5. resume
for i in g:
	print(i)
print(dir(g))
'''
#write a generator function
'''
input : n = 10
output: 20
		30
		40'''
'''
def increment(n):
	for i in range(2,5):
		yield n*i

for i in increment(10):
	print(i)'''
'''
#mimic the range function range(5):0-4 ; range(3,9,2): 3,5,7 ; 
#range(2,6):2,3,4,5	: range(start, stop, step)
def myRange(stop, start = 0, step = 1):
	x = start
	while x<stop:
		yield x
		x += step

print(list(myRange(5)))#0,1,2,3,4
print(list(myRange(9,3,2)))#3,5,7
print(list(myRange(6,2)))#2,3,4,5
'''
#closure
#remebers values of the enclosing even after it has been removed from the 
#memory
#1. nested function
#2. nested/inner fn must use a var from the outer fn
#3. the outer fn must return the inner fn obj
def make_multiplier(x):
	def multiplier(n):
		return(x*n)
	return multiplier

table2 = make_multiplier(2)
print(table2(3))
	
















		
		
		