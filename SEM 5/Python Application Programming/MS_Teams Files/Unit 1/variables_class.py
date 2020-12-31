class student:
    univ='pes'
    def __init__(self,name,age):
        self.name=name
        self.age=age
s1=student('rama',20)
s2=student('devi',20)
s2.age=25
print(s1.name,s1.age)
print(s2.name,s2.age)
print(student.univ)
