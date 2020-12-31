class Employee:
	pass

emp1 = Employee()
emp1.email = "some@gmail.com"
emp1.name = "hailey"
emp1.pay = 20

#################################

class Employee:

	def __init__(self, name, pay):

		self.name = name
		self.pay = 10
		self.mail = name + "@mail.com"


	def displName(self):
		print("Yo name : ", self.name)



emp2 = Employee("Corey", 20)
emp2.displName()
Employee.displName(emp2)

#################################

class Employee:

	raise_amt = 1.05
	num_emp = 0

	def __init__(self, name, pay):

		self.name = name
		self.pay = 10
		self.mail = name + "@mail.com"

		Employee.num_emp += 1

	def displName(self):
		print("Yo name : ", self.name)

	def apply_raise(self):

		self.pay = self.pay* self.raise_amt
		# self.pay = self.pay* Employee.raise_amt



emp2 = Employee("Corey", 20)
print(emp2.pay)
emp2.apply_raise()
print(emp2.pay)

## We make a new var in the namespace of emp2
## Since it first searches in own namespace then class name sapce then parent class
emp2.raise_amt = 1.08


## Print name spaces
print(emp2.__dict__)
print(Employee.__dict__)



##################################
## Static and Class methods

'''
Static methods, much like class methods, 
are methods that are bound to a class 
rather than its object. They do not 
require a class instance creation. 
So, they are not dependent on the state 
of the object.


A class method is a method that is bound 
to a class rather than its object. 
It doesn't require creation of a class 
instance, much like staticmethod. 
The difference between a static method 
and a class method is: ... 
Class method works with the class since 
its parameter is always the class itself.
'''


class Employee:

	raise_amt = 1.05
	num_emp = 0

	def __init__(self, name, pay):

		self.name = name
		self.pay = 10
		self.mail = name + "@mail.com"

		Employee.num_emp += 1

	def displName(self):
		print("Yo name : ", self.name)

	def apply_raise(self):

		self.pay = self.pay* self.raise_amt
		# self.pay = self.pay* Employee.raise_amt


	@classmethod
	def set_raise_amt(cls, amount):
		cls.raise_amt = amount

	# Alt constructor
	@classmethod
	def from_string(cls, emp_str):
		name, pay = emp_str.split("-")
		# create and return new object
		return cls(name, int(pay))


	@staticmethod
	def is_workday(day):
		if day == 5 or day == 6:
			return False
		else:
			return True


emp1 = Employee("Coby", 30)
emp2 = Employee("Corey", 20)

## Static methods n stuff
print(emp1.is_workday(5))


## Class methods and stuff

# Using class methods as alt constructors
# Datetime module is a good use case for this
emp3 = Employee.from_string("Garret-40")

print(emp1.raise_amt)
print(emp2.raise_amt)

# We can use class nam or any instance of the class
# to run the class method.
# Class methods can be used as alternate constructors
Employee.set_raise_amt(1.09)
emp1.set_raise_amt(1.11)


print(emp1.raise_amt)
print(emp2.raise_amt)




##################################################
## INHERITANCE

class Developer(Employee):
	def __init__(self, name, pay, language):
		
		# USe one of the two ways
		# preferably super
		# to let the parent class handle their stuff
		super().__init__(name, pay)
		Employee.__init__(self, name, pay)

		self.language = language


# Method resolution order should be known
# Each class in python inherits from builtins.object class
dev1 = Developer("Tyler", 50, "Python")
print(help(Developer))

## Instance and Subclass check
print(isinstance(dev1, Employee))
print(issubclass(Developer, Employee))



###################################################
## Getters and setters

class Employee:

	def __init__(self, first, last):
		self.first = first
		self.last = last
	
	# Getter method
	@property	
	def email(self):
		return first+last+"@gmail.com"

	@property
	def fullname(self):
		return first+ " "+last

	# Setter
	@fullname.setter
	def fullname(self, name):
		first, last = name.split(" ")
		self.first = first
		self.last = last

	# setter / deleter
	@fullname.deleter
	def fullname(self):
		print("delete name")
		self.first = None
		self.last = None


emp1 = Employee('John', "Carter")

print(emp1.email)

del emp1



##################################################
## Private variables in python

## We must write getters and setters for those

## Way we use protected 			: _protectedVariableName
## Way we write private variable 	: __privateVariableName 

print(emp1._protectedVariableName) # this works
print(emp1.__privateVariableName) # this gives error
print(emp1._Employee__privateVariableName) # this works













###################################################
## GENERATORS

def print_nums(nums):

	for i in nums:
		yield i

res = print_nums(list(range(10)))

for i in res:
	print(i)

# Another way to create generator
myNums = (x*x for x in [1,2,3,4,5])




###################################################
## CLOSURES



# First Class func : which can be assigned , passed , retruned

# Assigning a function to another variable
def square(n):
	return n*n

# Getting result
result = square(4)

# Assigning
obj_sqr = square
print(obj_sqr(5))



## Passing a func as argument
def some_random_func(func, nums):

	result = []
	for i in nums:
		result.append(func(i))

	return result

ans = some_random_func(square, [1,2,3,4])

print(ans)



## returning functions
def logger(msg):

	def log_msg():
		print("msg : ", msg)

	return log_msg

# It will remember the stuff we passed / remember state
log_hi = logger("Hi")
log_hi()

	


