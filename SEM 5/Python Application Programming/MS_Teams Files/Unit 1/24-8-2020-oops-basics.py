#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Aug 24 13:20:14 2020

@author: P Rama Devi

"""
'''class csfaculty:
    def __init__(self,exp,domain):#special method
        self.exp=exp
        self.domain=domain
        print("in init")
    def expertize(self):
        print("in...........")
    def show(self):
        print(self.exp,self.domain)
f1=csfaculty(10,"CV,IP")
f2=csfaculty(4,"WEB")
#csfaculty.expertize()
#csfaculty.expertize()
f1.expertize() #behind the scenes csfaculty.expertize(f1)
f2.expertize()
print(f1.domain)
print(f2.domain)
f1.show()
f2.show()
'''

class student:
    def __init__(self,name,rollno,m1,m2):
        self.name=name
        self.rollno=rollno
        self.m1=m1
        self.m2=m2
    def avg(self):
        return (self.m1+self.m2)/3;
s1=student('xyz',123,65,23)
s2=student('abc',132,34,45)
print(s1.avg())
print(s2.avg())

    
        
        
        
        
        





