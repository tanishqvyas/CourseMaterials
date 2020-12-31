#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 15 14:03:04 2020

@author: P Rama Devi
"""
'''
[] - matches characters in brackets
[^] - matches characters not in bracket
| - either or
() - group

quantifiers

* - 0 or more
+ - 1 or more
? - 0 or one
{1} - exact number
{1,3} - range of numbers(min,max)

groups - () 
'''
#regular expressions
'''
import re
text='''
Mr. Sachin
Mr Virat
Mrs Karanam
Ms Sindhu
Mr. R

'''

pattern = re.compile(r'(Mr|Ms|Mrs)\.?\s[A-Z]\w*')
matches=pattern.finditer(text)
for match in matches:
    print(match)
'''

emails='''
ramadevi@gmail.com
rama.devi@pes.edu
p-rama-devi@my-work.net
'''

pattern = re.compile(r'[a-zA-Z.]+@[a-zA-Z]+\.(com|edu)')
matches=pattern.finditer(emails)
for match in matches:
    print(match)








