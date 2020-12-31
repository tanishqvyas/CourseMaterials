# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import re
text_to_search='''
abcdef.....
ABCDEF.....
abc
abc
rama.com
devi*edu
0123456789
Ha HaHaHaHaHa
^ -  begining of the string
$ - end of the string

011--34567
040-12345
080-67890
020-34512
040.56789
020*12345   [^23].....
200-12345
300-56432
200.34567
400-34213
500-34567

varun
tarun
karun
parun

'''

'''
\d   - 0-9
\D   - negates \d
\w  -  word character (a-z, A-Z, 0-9, _)
\W - negates \w
\s  -  white space (tab newline)
\S   -   negates \s
\b  -   word boundary
\B  -  not a word boundary

character sets

[]  -  matches the characters in the bracket
[^ ]   -  matches characters not in brackets
[1 - 5]  - range 

quantifiers

matches one or more characters

*  -  0 or more
+   -  1 or more 
?  -  0 or  1
{3}  -  exact number
{3,4}  -  range of numbers 


'''
sentence='start with a end start end beautiful smile end'
#print(r'\nnewline')
pattern=re.compile(r'[^p]arun')
matches=pattern.finditer(text_to_search)
for match in matches:
    print(match)
    
    
    
    