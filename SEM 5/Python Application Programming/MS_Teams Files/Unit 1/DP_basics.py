#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep  1 14:21:20 2020

@author: P Rama Devi
"""
#GOF book 23 design patterns

# creational design pattern

'''
singleton : how objects are created
factory
builder
prototype
etc.
# structural design pattern

'''
'''
adaptor
decorator
facade
proxy
etc...
'''
# behavioural design pattern
'''
oberver
state
template
etc...

'''
'''
class single:
    instance=None
    def getinstance():
        if single.instance==None:
            single()
        return single.instance
    def __init__(self):
        if single.instance!=None:
            raise Exception("this is single")
        else:
            single.instance=self
s=single()
print(s)
#s1=single()
s=single.getinstance()
print(s)
'''

#borg design pattern or monostate design pattern

#allow me to create multiple instances for same class but share same state

# __dict__
'''
class test:
    def __init__(self,name):
        self.name=name
t1=test('rama')
print(t1.__dict__['name'])
#print(test.__dict__)

'''
# create multiple instances for the same class but they all should share same state

class borg:
    _shared={}
    def __init__(self):
        print(self._shared)
        self.__dict__=self._shared
        print(self.__dict__)
class singleton(borg):
    def __init__(self,name):
        borg.__init__(self)
        self.name=name
o1=singleton('rama')
print("o1",o1)
print("o1 name",o1.name)
o2=singleton('devi')
print("o2",o2)
print("o2 name",o2.name)
print("o1 name",o1.name)
