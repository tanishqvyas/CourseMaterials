#Design Pattern : facade
'''1.Backend:collection of subsystems
2.Interface:Facade
3.client:Entry point of the system'''
#Automation testing platform
import time
#backend / subsystems
class TestC1:
	def run(self):
		print("#### in test case 1 ####")
		time.sleep(1)
		print("Setting up")
		time.sleep(1)
		print("Running test")
		time.sleep(1)
		print("tearing Down")
		time.sleep(1)
		print("Test 1 completed")

class TestC2:
	def run(self):
		print("#### in test case 1 ####")
		time.sleep(1)
		print("Setting up")
		time.sleep(1)
		print("Running test")
		time.sleep(1)
		print("tearing Down")
		time.sleep(1)
		print("Test 2 completed")

class TestC3:
	def run(self):
		print("#### in test case 1 ####")
		time.sleep(1)
		print("Setting up")
		time.sleep(1)
		print("Running test")
		time.sleep(1)
		print("tearing Down")
		time.sleep(1)
		print("Test 3 completed")
#interface : Facade
class TestRunner:
	def __init__(self):#object composition : "has a" relationship
		self.tc1 = TestC1()
		self.tc2 = TestC2()
		self.tc3 = TestC3()
	def runAll(self):
		self.tc1.run()
		self.tc2.run()
		self.tc3.run()
#Client interaction
if __name__ == '__main__':
	testrunner = TestRunner()
	testrunner.runAll()




