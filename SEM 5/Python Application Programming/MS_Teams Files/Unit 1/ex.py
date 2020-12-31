class abc:
    class_attr="class_attribute"
    def __init__(self,attr1,attr2):
        self.attribute1=attr1
        self.attribute2=attr2
    def method1(self):
        print("rama")
    def method2(self):
        print("devi")
    def disp(self):
        print(self.attribute1,self.attribute2)
    @classmethod
    def class_method(cls):
        return cls.class_attr
    @staticmethod
    def static_method():
        a='rama'
        b='devi'
        return a+b
object1=abc("attr1","attr2")
object2=abc("attr1","attr2")
abc.method1(object)
object1.method1()
object1.method2()
abc.method2(object1)
object1.disp()
object2.disp()
print(object1.attribute1)
print(object1.attribute2)
print(object2.attribute1)
print(object2.attribute2)
object1.attribute1="attribute1"
print(object1.attribute1)
print(abc.class_attr)
abc.class_method()
print(abc.static_method())
