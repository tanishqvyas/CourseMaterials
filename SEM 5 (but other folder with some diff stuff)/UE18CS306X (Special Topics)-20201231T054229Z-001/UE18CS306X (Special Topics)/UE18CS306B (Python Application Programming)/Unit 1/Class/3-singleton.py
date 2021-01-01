class Singleton:
   __instance = None #private static var
   
   def __init__(self):
      """ Virtually private constructor. """
      if Singleton.__instance != None:
         raise Exception("This class is a singleton!")
      else:
         Singleton.__instance = self
   @staticmethod 
   def getInstance():
      if Singleton.__instance == None:
         Singleton()
      return Singleton.__instance
s = Singleton()
print (s)
#s = Singleton()
s = Singleton.getInstance()
print (s)
s = Singleton.getInstance()
print (s)