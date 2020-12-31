class student:
    def __init__(self):
        self.name='rama'
        self.age=20
    def compare(self,s2):
        if self.age==s2.age:
            return True
        else:
            return False
        
s1=student()
s2=student()
s2.age=10
s2.name='devi'
print(s1.age)
print(s2.age)
if s1.compare(s2):
    print("same")
else:
    print("diff")
print(s1.name)
print(s2.name)
