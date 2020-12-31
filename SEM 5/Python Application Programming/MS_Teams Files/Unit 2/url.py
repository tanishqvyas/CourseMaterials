#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 15 15:04:22 2020

@author: csestaff
"""

import re
text='''
Mr. R
Ms. Devi
Mrs Karuna
'''
pattern=re.compile(r'(Mr|Ms|Mrs)\.?\s[A-Z]\w*')
matches=pattern.findall(text)
for match in matches:
        print(match)
        
#Adaptor - structural DP







