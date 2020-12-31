'''

Metacharacters (Need to be escaped)

.[]{}()^$|?*+\

'''




import re

text_to_search = """

tanishqvyas0692gmail.com

1234567890101
22-2-2--2-2
a222-333-444
111-222-444
000-003-787
abcdefghijklmnoq

"""


# pattern = re.compile( WRITE UR PATTERN HERE)
pattern = re.compile(r"a(\d{3})[-](\d{3})[-](\d{3})")
pattern1 = re.compile(r"gullu", re.IGNORECASE)


#  re.sub(pattern, repl, string, count=0, flags=0)
print(re.sub('ub', '~*' , 'Subject has Uber booked already', flags = re.IGNORECASE)) 

substitued_pattern = pattern.sub(r"Phonewa : \1-\2-\3", text_to_search)

matches = pattern.finditer(text_to_search)

for match in matches:
	# print(match)
	print(match.group(0))

print(substitued_pattern)




# findall : returns the matches as list of strings
findings = pattern.findall(text_to_search)
print("Findings")
print(findings)
for i in findings:
	print(i)


# match : returns the first match else None
# This dumbo matches just the beginning of str :facepalm
found_match = pattern.match(text_to_search)
print("found_match : ", found_match)


# search : searches throught
found_search = pattern.search(text_to_search)
print("found search : ", found_search.group(0))


'''
DOTALL is the other flag related to multiline text. 
Normally the dot character . matches everything in the input 
text except a newline character. 
The flag allows dot to match newlines as well.t


The re. MULTILINE flag tells python to make the '^' and '$' 
special characters match the start or end of any line 
within a string. 
Using this flag: >>> match = re.search(r'^It has.

Latest Python tidbit: the re module has an option to write 
regular expressions in re. VERBOSE format. This means that 
whitespace can be used to layout the regular expression in 
a more readable style, and comments can be included with 
hash marks.
'''