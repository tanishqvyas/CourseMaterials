#regular Expressions
#import re
#characters
'''
repetion symbols
. - any characters a single
a+ - one or more 'a'
a? - 0 or 1 occurence
a* - 0 or more
{n} - repeated n times : a{3}
{n,m} - a{2,5}

Anchor characters
^ - beginning of the string
$ - pattern to occur at the end of the string
\b - boundary - '\bthe\b'
\B - ignore pattern find it within a word

MetaCharacters
[] - character Classes
[012] : 1 2 0
[0-9][0-9] or [0-9]{2}: 12 23 34 54
[pattern]{min_occurences, max_occurences}
[a-z] [A-Z]{2,4}: ab abc abcd
. - any char
[.] - matches the dot
^ - anchor tags :starts with
[^] - inversion, negation [^aeiou]
$ - ends with
pattern - '^[0-9]..[0-9]$' : 1gt9
+ - one or more: .+ [0-9]+
* - zero or more
? - zero or ONE occurence

'''
'''
#validate SRN
import re
srn = input("Enter your SRN: ")#PES2201800123
pattern = "PES220180{2}[0-9]{3}"
if re.search(pattern,srn):
	print("Valid srn")
else:
	print("invalid srn")
	
#validate email.id
import re
email = input("Enter your email id: ")#xyz.abc@gmail.com #abc@yahoo.com
pattern = "^[a-z]+\.?[a-z]+@[a-z]+\.[a-z]{3}$"
if re.search(pattern,email):
	print("Valid email address")
else:
	print("invalid email address")
'''
#escape codes:
'''
[0-9] or \d  - digit
[^0-9] or \D - non-digit

[ ] or \s - whitespace
[^ ] or \S - non

[a-z0-9] or \w - Alphanumeric
[^a-z0-9] or \W - non - Alphanumeric

^ or \A - start of a string
$ or \Z - end of the string
'''
'''
#validate Phone number
import re
num = input("Enter your phone number: ")
#my number is +91-9844820045
pattern = "\+\d{2}-\d{10}" 
#"\+[0-9]{2}-[0-9]{10}"
match = re.match(pattern,num)
if match:
	print("Valid phone number ",match.group())
else:
	print("invalid phone number")

'''
'''
import re
num = input("Enter your phone number: ")
#my number is +91-9844820045
pattern = "\+\d{2}-(\d{10})" #grouping of patterns
#"\+[0-9]{2}-[0-9]{10}"
match = re.findall(pattern,num)
if match:
	print("Valid phone number ",match)
else:
	print("invalid phone number")
'''
'''
import re
word= input("Enter a word to match: ")
pattern = '(h|p).t'
match = re.search(pattern,word)
if match:
	print("valid word",match.group())
else:
	print("invalid word")
'''
#calculate the average confidence value
#of a given mailbox's spam folder
#X-DSPAM-Confidence: 0.8475
'''
import re
c = []
with open('spam.txt','r') as f:
	for line in f:
		pattern = '^X\S+: (0\.\d+)'
		m = re.findall(pattern,line)
		if m:
			c.extend(m)
c = list(map(float,c))
avg = sum(c)/len(c)
print("Average Confidence Value",avg)		
'''
#24/09/2020
import re
text = 'This is a sample string in python'
pattern = '\s(\w{2})\s'
#findall
'''
for match in re.findall(pattern,text):
	print(match)
#finditer
for match in re.finditer(pattern,text):
	print(match.group())
#fullmatch
text = ' is '
pattern = '\s(\w{2})\s'
print(re.fullmatch(pattern,text))

#compiling expressions
text = 'This is a sample string in python'
pattern = '\s(\w{2})\s'
regex = re.compile(pattern)
for match in re.findall(pattern,text):
	print(match)
print()
for match in regex.findall(text):
	print(match)
#print(dir(regex))

#search options
text = 'This is a sample string that demostrates this function'
pattern = 'This'
regex = re.compile(pattern, re.IGNORECASE)
for match in regex.findall(text): 
	print(match)
	
text = 'This is a sample string \nthat demostrates this function'
pattern = '^\w*'
regex = re.compile(pattern, re.MULTILINE)
for match in regex.findall(text): 
	print(match)

text = 'This is a sample string\nthat demostrates this function'
pattern = '.*'#except \n
regex = re.compile(pattern,re.DOTALL)
print(regex.findall(text))
'''
#verbose
text = 'neeta.jacob@pes.edu'
pattern = '''^
[a-z]+	#first name
\.?		#0 or 1 dot
[a-z]+	#last name
@
[a-z]+	#mailserver
\.
[a-z]{3}#domain
$'''
regex = re.compile(pattern, re.VERBOSE)
#print(regex.findall(text))

#modifying strings with patterns
'''
bold = re.compile('\*{2}(.*)\*{2}')
text = 'this is in **bold-face** format'
print('Text:',text)
print("Bold:", bold.sub(r'<b>\1</b>',text))
'''
#splitting with patterns
text = '''Paragraph one
on two lines.

paragraph two.

paragraph three.


'''
for num,para in enumerate(re.findall('(.+?)\n{2,}',text,flags = re.DOTALL)):
	print(num , para)
print()









