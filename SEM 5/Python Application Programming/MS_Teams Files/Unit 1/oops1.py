class faculty:
    def __init__(self,name,course):
        self.name=name
        self.course=course
    def info(self):
        print(self.name,self.course)


f1=faculty('rama','dm')
f2=faculty('devi','cv')
f1.info()
f2.info()
print(id(f1))
print(id(f2))
    
    

