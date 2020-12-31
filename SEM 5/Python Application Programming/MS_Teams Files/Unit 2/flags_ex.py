'''import re
text='is this is novel idea'
pat='is'
x=re.match(pat,text)
y=re.findall(pat,text)
z=re.search(pat,text)
print('match',x)
print('find all',y)
print('search',z)'''

#MULTILINE DOTALL VERBOSE UNICODE FLAGS

#import re
#ss='''rama
#kavitha
#manasvi
'''
r1=re.findall('^\w*',ss)
r2=re.findall('^\w*',ss,flags=re.MULTILINE)
print(r1)
print(r2)'''

#import re
#ss='''today is tuesday
#and we are in pap class'''
'''r1=re.findall(".+",ss)
r2=re.findall(".+",ss,re.DOTALL)
print(r1)
print(r2)'''

'''import re
address=re.compile('[\w\d.+-]+@([\w\d.]+\.)+(com|org|edu)')
candidates=[
'rama.devi@ex.com',
'rama.devi+faculty@gmail.com',
'my-address@mail.ex.com',
'not-valid@ex.gov']
for candidate in candidates:
        match=address.search(candidate)
        print(match)
'''
'''import re
address=re.compile(
'''
#[\w\d.+-]+  #username
#@
#([\w\d.]+\.)+ #domain name
#(com|org|edu) #toplevel domain name''',re.VERBOSE)
#candidates=[
'rama.devi@ex.com',
'rama.devi+faculty@gmail.com',
'my-address@mail.ex.com',
'not-valid@ex.gov']
#for candidate in candidates:
 #       match=address.search(candidate)
  #      print(match)


