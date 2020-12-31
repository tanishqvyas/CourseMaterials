## Design Patterns


# Creational Patterns: 
These design patterns provide ways to create objects while hiding the creation logic, instead of instantiating objects directly using the new operator. This gives the program more flexibility in deciding which objects need to be created for a given use case.

#Structural Patterns: 
These design patterns deal with class and object composition. The concept of inheritance is used to compose interfaces and define ways to compose objects to obtain new functionality.

# Behavioral Patterns: 
These design patterns are specifically concerned with communication between objects.


# Singleton Design Pattern 	:

In singleton pattern we ensure that a class has only one instance and we provide a global point of access to that.
(People usually argue that we should not use signleton design pattern.)

They kinda make the constructor of the class prib=vate to prevent creation of objects/instances of the same class from outside.


```
class Singleton:
   __instance = None
   @staticmethod 
   def getInstance():
      """ Static access method. """
      if Singleton.__instance == None:
         Singleton()
      return Singleton.__instance
   def __init__(self):
      """ Virtually private constructor. """
      if Singleton.__instance != None:
         raise Exception("This class is a singleton!")
      else:
         Singleton.__instance = self

inst1 = Singleton()
print(inst1)

inst2 = Singleton.getInstance()
print(inst2)

inst3 = Singleton.getInstance()
print(inst3)

```



# Facade Design Pattern 	:


Definition : The facade pattern pattern provides a unified interface to a set of possibly inter-related interfaces in a sub system. Facade defines a higher level interface that makes the subsystem easier to use. 

If we have a bunch of things and if we have different interactions going on among these things.
Then we have a (client) a piece of code that kinda wants to use that piece of code.

Basically underneath the facade we have all the plumbing but outside i need not worry/deal with all that plumbing all the time. So i create a facade and this facade interacts with all the wiring when the client interacts with the facade.

Client -------> Facade ---------> All complex plumbing n stuff

Thus facade simplieifes the interaction for the client by acting as an intermediary. That is the facade actually interacts with all the underlying shit.

Thus implementing **Law of Demeter / Principle of Least Knowledge** : Ur only allowed to interact/invoke methods of urself or of the objects ur directly interacting with. Not of those who are interacting with the object you are interacting with.



# Observer Design Pattern 	:

Usually multiple enteties polls/keeps asking to our entity about change in their state. So the observer pattern instead says its a bad idea and makes us to switch from this case to Pushing. Thus whenever our entetity changes state, its his responsibility tp push the new state to the askers. This in essence is observer pattern.

Observable is being observed by observers. Before the observers can get the push update they must subscribe to receive it. That is when observable changes / subject changes then the observers are notified.

Actual definition : The observer defines a one to many dependency between objects so that one object changes state, all of its dependencies are notified and updated automatically.


Functions / Implementations we need : 

1. Observable
	
	- Register() 	: To register the observers
	- Remove()	 	: To remove the observers from the registered observers' pool
	- Notify()	 	: To notify/Broadcast info to the observers about the change in state
	- getState()	: To get the current state
	- setState()	: To change the current state to smthg new

2. Observer
	
	- Update 		: This is called on each instance of the observer once the are notified about the change.



```
import threading
import time
import pdb

class Downloader(threading.Thread):
   
   def run(self):
      print('downloading')
      for i in range(1,5):
         self.i = i
         time.sleep(2)
			print('unfunf')
         return 'hello world'

class Worker(threading.Thread):
   def run(self):
      for i in range(1,5):
         print('worker running: %i (%i)' % (i, t.i))
         time.sleep(1)
         t.join()

         print('done')

t = Downloader()
t.start()

time.sleep(1)

t1 = Worker()
t1.start()

t2 = Worker()
t2.start()

t3 = Worker()
t3.start()

```




# Adapter Design Pattern 	:

Its mainly about taking two interfaces which arent compatible and making them compatible. An adapter is kinda like a wrapper that wraps on a stuff and thus makes it compatible with the other peeps.

Definition : The adapter converts the interface of a class into another interface clients expect. This allows the classes to work together which couldn't otherwise.


# Proxy Design Pattern     :

