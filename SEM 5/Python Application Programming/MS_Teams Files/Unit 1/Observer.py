#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep  3 13:51:20 2020

@author: P Rama Devi
"""

#techforum and the users

class publisher:
    def __init__(self):
        pass
    def register(self):
        pass
    def unregister(self):
        pass
    def notifyall(self):
        pass

class techforum(publisher):
    def __init__(self):
        self.listofusers=[]
        self.postname=None
    def register(self,userobj):
        if userobj not in self.listofusers:
            self.listofusers.append(userobj)
    def unregister(self,userobj):
        self.listofusers.remove(userobj)
    def notifyall(self):
        for objects in self.listofusers:
            objects.notify(self.postname)
    def writenewpost(self,postname):
        self.postname=postname
        self.notifyall()

class subscriber:
    def __init__(self):
        pass
    def notify(self):
        pass
class user1(subscriber):
    def notify(self,postname):
        print("user1 is notified of a new post ",postname)
class user2(subscriber):
    def notify(self,postname):
        print("user2 is notified of a new post ",postname)  
'''class sistersites(subscriber):
    def __init__(self):
        self.sisterwebsites=["site1","site2","site3"]
    def notify(self,postname):
        for site in self.sisterwebsites:
            print("send notification to site:",site)'''
t1=techforum()
u1=user1()
u2=user2()
#s1=sistersites()
t1.register(u1)
t1.register(u2)
#t1.register(s1)
t1.writenewpost("an article on gan's")
t1.unregister(u1)
t1.writenewpost("an article on dl")








