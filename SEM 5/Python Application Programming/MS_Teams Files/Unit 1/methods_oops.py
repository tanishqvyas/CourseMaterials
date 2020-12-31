class student:
    univ='pes'
    def __init__(self,m1,m2,m3):
        self.m1=m1
        self.m2=m2
        self.m3=m3
    def avg(self):
        return (self.m1+self.m2+self.m3)/3
    @classmethod
    def info(cls):
        return cls.univ
    @staticmethod
    def cal():
        m=60
        return m/3
s1=student(1,2,3)
s2=student(3,4,5)
print(s1.avg())
print(s2.avg())
print(student.info())
print(student.cal())
