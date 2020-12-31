import re
text='''
Mr. Rama
Mr Kevin
Ms Kavitha
Mrs. devi
Mr. R
'''
pattern=re.compile(r'Mr\.?')
matches=pattern.finditer(text)
for match in matches:
	print(match)
