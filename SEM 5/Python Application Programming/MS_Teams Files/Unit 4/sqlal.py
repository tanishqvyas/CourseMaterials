"""#sqlalchemy
from sqlalchemy import create_engine, MetaData, Table, Column, Integer, String
engine=create_engine('sqlite:///col1.db', echo=True)
meta=MetaData()
students=Table('students',meta,
Column('srn',Integer,primary_key=True),
Column('name',String),
Column('course', String),
)
meta.create_all(engine)
conn=engine.connect()
"""
"""conn.execute(students.insert(),[
{'name':'ram','course':'MI'},
{'name':'neha','course':'AA'},
{'name':'lavithra','course':'big data'},
{'name':'rishit','course':'data analytics'},
])"""
"""
s=students.select()
result=conn.execute(s)
for row in result:
	print(row)
s1=students.select().where(students.c.course=='MI')
result1=conn.execute(s1)
for row in result1:
	print(row)
#update 
s2=students.update().where(students.c.course=='MI').values(course='MUSIC')
conn.execute(s2)
ss=students.select()
result2=conn.execute(ss)
for row in result2:
	print(row)
#delete()
s3=students.delete().where(students.c.course=='MUSIC')
conn.execute(s3)
ss1=students.select()
result3=conn.execute(ss1)
for row in result3:
	print(row)
"""
#foreign key constraint
from sqlalchemy import create_engine, MetaData, Table, Column, Integer, String,ForeignKey
engine=create_engine('sqlite:///col1.db', echo=True)
meta=MetaData()
students_main_office=Table('students_main_office',meta,
Column('srn',Integer,primary_key=True),
Column('name',String),
Column('course', String),
)

conn=engine.connect()

students_dept=Table('students_dept',meta,
Column('drn',Integer,primary_key=True),
Column('email_id',String),
Column('address',String),
Column('srn_dept',Integer,ForeignKey('students_main_office.srn')),
Column('phone_number',Integer))
meta.create_all(engine)

# 1. print all the rows whose address is bangalore
# 2. print all student rows whose course is big data
























#conn.execute(s).fetchall()

