#sql alchemy
# how nice it would be if we have a mediator
from  sqlalchemy import create_engine, MetaData, Column, Integer, String, Table 
engine=create_engine('sqlite:///college.db',echo=True)
meta=MetaData()
students=Table('students',meta,
Column('srn',Integer, primary_key=Ture),
Column('name',String),
Column('firstname',String),)
#insert method is used which is there in students
i1=students.insert().values(srn=123,name='ram',firstname='p')
conn=engine.connect()
result=conn.execute(i1)
"""s=students.select()
conn=engine.connect()
result=conn.execute(s)
for row in result:
	print(row)
"""

"""
CREATE TABLE students(
srn INTEGER NOT NULL,
name VARCHAR,
.....
conn.execute(students.insert(),[
{'srn':123,'name':'ram','firstname':'p'},
'''
''''
'''

)
