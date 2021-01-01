#Neeta Ann Jacob
#9844820045
#neetajacob@pes.edu

#class 1: 24/08/2020
#classes and Objects
#what : attribute
#how : method/function
'''
class Enemy:
	#life = 3	
	def __init__(self,weapon):
		#attributes:what
		self.life = 3
		self.weapon = weapon
		#print("constructor called ",self.life)
	#behavior:how
	def attack(self):
		self.life -= 1

#print(Enemy)#class
e1 = Enemy("Gun")#Enemy.__init__(e1)
#print(e1,type(e1))
print(e1.__dict__)
e1.attack()#object method
print("life = ",e1.life)#object attribute
'''
#class 2: 29/08/2020
'''
class Enemy:	
	def __init__(self,weapon):
		self.life = 3
		self.weapon = weapon
		
	def attack(self):
		self.life -= 1
#creating object attributes dynamically
e1 = Enemy("gun")
#print(dir(e1))
print(e1.__dict__)
e1.position = (10,35)#e1 has an additional property
#does not alter the class definition
print(e1.__dict__)

e2 = Enemy("sword")
print(e2.__dict__)

'''
#overriding
'''
def f1():
	print("1")

def f1():
	print("2")

f1()#2

x = 23
x = 45
print(x)#45
'''

'''
class Enemy:	
	def __init__(self,weapon):
		self.life = 3
		self.weapon = weapon
		
	def attack(self):
		self.life -= 1
	
	def __str__(self):#overriding the default str method
		return "This is an enemy object"
	
e1 = Enemy("gun")

#iterating through  object attributes and methods
print(e1)
print(dir(e1))
print()
attr = [i for i in dir(e1) if not i.startswith("__")]

for i in dir(e1):
	if not i.startswith("__"):
		print(i)

print(attr)
'''
#copy one object to another
'''
class Enemy:	
	def __init__(self,weapon):
		self.life = 3
		self.weapon = weapon
		
	def attack(self):
		self.life -= 1
		
e1 = Enemy("gun")
e1.attack()
print(e1.life)
#e1.position = (10,35)
#e1.lif = 3
setattr(e1,"position",(10,35))#create obj attr dynamically
e2 = Enemy("gun")
e2.__dict__.update(e1.__dict__) #copies values using dictionary methods
print(e2.life)
temp = vars(e1)
print(temp,type(temp))
for i in temp:
	print(i,":",temp[i])
'''
#class/static variables
'''
#scope of variables in functions
count = 3 #global
def outer():
	count = 1
	def inner():
		#global count #accesses count from line 114
		#nonlocal count #accesses count line 116
		count = 2#local>global
	inner()
	print("Outer count = ", count)
outer()
print("global count = ",count)
'''
'''
class Enemy:
	count = 0#static variables, only accessed via class name
	def __init__(self,weapon):
		self.life = 3
		self.weapon = weapon
		Enemy.count+=1 #class/static var
		#self.count +=1#object attribute
		#count = 1#local var
		
	def attack(self):
		self.life -= 1
	def __del__(self):
		Enemy.count -= 1	

e1 = Enemy("Gun")	
print(e1.__dict__ , Enemy.count)
e2 = Enemy("Gun")	
print(e2.__dict__ , Enemy.count)
del e1
#print(e1)
print(Enemy.count)
'''
#staticmethod
'''
class Enemy:
	count = 0#static variables
	def __init__(self,weapon):
		self.life = 3
		self.weapon = weapon
		Enemy.count+=1 #class/static var
		
	def attack(self):
		self.life -= 1		
	def __del__(self):
		Enemy.count -= 1	
	@staticmethod #optional : prefered way
	def enemyCount():#static Method
		print("Number of Enemies : ",Enemy.count)#only access class/static var
e1 = Enemy("Gun")	
print(e1.__dict__ , Enemy.count)
e2 = Enemy("Gun")	
print(e2.__dict__ , Enemy.count)
print(Enemy.count)# 2 2 #called using class name
e1.enemyCount()
'''
#Object Composition : "has a" relationship
#Enemy "has a" weapon
'''
class Weapon:
	def __init__(self,type):
		self.type = type
	def display(self):
		print("The weapon is a",self.type)

class Enemy:#has a weapon object
	def __init__(self,weaponName):
		self.life = 3
		self.weapon = Weapon(weaponName)
		
	def attack(self):
		self.life -= 1

e1 = Enemy("Gun")
e1.weapon.display()
print(e1.weapon.type)
w1 = Weapon("Sword")#independent object
w1.display()
'''
#class 3: 01/09/2020
#inheritance : "is a" relationship
#Enemy "is a" person
'''
class Person:#super / Parent class
	def __init__(self,id,gender):
		self.id = id
		self.gender = gender
	def display(self):
		print("id:", self.id,"Gender:",self.gender)

class Enemy(Person):#child class
	def __init__(self,weapon,id,gender):
	
		Person.__init__(self,id,gender)#mandatory
		self.weapon = weapon
		self.life = 3
	def display(self):
		#Person.display(self) #or
		super().display()
		print("Weapon:",self.weapon,"Life:",self.life)
#class name(class1,class2):
class Player(Enemy):
	def __init__(self,weapon,id,gender,name):
		Enemy.__init__(self,weapon,id,gender)
		self.name = name
p1 = Player("Sword",2,"F","Black widow")
print(dir(p1))

e1 = Enemy("Gun",1,"M")
e1.display()
'''
#print(e1.id,e1.gender)
'''
print(dir(e1))
p1 = Person(1,"M")		
print(dir(p1))
'''	
#private Variables and methods
#pritvate attributes: cannot be accessed outside the class
#inheritance: not inherited, but can be accessed through parent class methods
'''
class Person:#super / Parent class
	def __init__(self,id,gender):
		self.__id = id#private attribute# only accessible
		self.gender = gender#inherited
	def display(self):
		print("id:", self.__id,"Gender:",self.gender)
	def setvalue(self,newid):
		self.__id = newid

class Enemy(Person):#child class
	def __init__(self,weapon,id,gender):
		Person.__init__(self,id,gender)#mandatory
		self.weapon = weapon
		self.life = 3
	def display(self):
		super().display()
		print("Weapon:",self.weapon,"Life:",self.life)
e1 = Enemy("Gun",2,"M")
print(dir(e1))
e1.setvalue(3)
e1.display()

#Multiple inheritance
level 1 : class1	class2
			\		/
level2: 	  class3

#multilevel inheritance
level 1: class1	
			|
level2:  class2
			|
level3:  class3
'''
#p1 = Person(1,"F")
#print(p1.__id)
#p1.display()

#class 4 : 03/09/2020
#iterators
#iterable
# iterator - container
'''
for i in iter(range(5)):
	print(i)
	
i = next(i)
i = next(i)
..
..
..
stopIteration Exception
[0,1,2,3,4]
 |
	|
		|
			|
			'''

#iterator
# walk through the elements in the collection
# indicate the end of the collection
'''
class count:
	def __init__(self):
		pass
		
	def __iter__(self):
		self.i = 0
		#return the object
		return self
		
	def __next__(self):
		if self.i < 5:
			x = self.i
			self.i+=1
			return x
		else:
			raise StopIteration


for a in c1:#for a in iter(c1):
	print(a)
'''
'''
class myList:
	def __init__(self,collection):
		self.collection = collection
	
	def __iter__(self):
		self.i = 0
		return self
	
	def __next__(self):
		if self.i<len(self.collection):
			x = self.collection[self.i]
			self.i += 1
			return x
		else:
			raise StopIteration

l = myList((1,2,3))		

for x in iter_1:
	print(x)
'''
#class iterator:
'''	
class myList:
	def __init__(self,collection):
		self.c = collection
	def __iter__(self):
		self.i = 0
		return self
	def __next__(self):
		if self.i<len(self.c):
			x = self.c[self.i]
			self.i += 1
			return x
		else:
			raise StopIteration			
			
l = myList((10,20,30))	#l => container	
iter_1 = iter(l)
iter_2 = iter(l)
print(next(iter_1))	#10		
print(next(iter_2)) #20
'''		
class MyContainer:
	def __init__(self,collection):
		self.c = collection
	def __iter__(self):
		return Iterator(self)
'''
class Iterator:
	def __init__(self,list):#list => a container object
		self.c = list.c
		self.i = 0
	def __next__(self):
		if self.i<len(self.c):
			x = self.c[self.i]
			self.i += 1
			return x
		else:
			raise StopIteration
'''	
l = MyContainer((10,20,30))		
iter_1 = iter(l)
iter_2 = iter(l)
print(next(iter_1))			
print(next(iter_2))



		
class myList:
	def __init__(self,collection):
		self.c = collection
	def __iter__(self):
		self.i = 0
		return self
	def __next__(self):
		if self.i<len(self.c):
			x = self.c[self.i]
			self.i += 1
			return x
		else:
			raise StopIteration			
				
	
	















