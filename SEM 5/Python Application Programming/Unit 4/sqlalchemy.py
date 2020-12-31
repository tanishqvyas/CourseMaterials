from sqlalchemy import create_engine, MetaData, Table, Column, Integer, String, select, text
engine = create_engine('sqlite:///college.db', echo = True)
meta = MetaData()

students = Table(
   'students', meta, 
   Column('id', Integer, primary_key = True), 
   Column('name', String), 
   Column('lastname', String), 
)

ins = students.insert()
ins = students.insert().values(name = 'Ravi', lastname = 'Kapoor')
conn = engine.connect()
result = conn.execute(ins)

conn.execute(students.insert(), [
   {'name':'Rajiv', 'lastname' : 'Khanna'},
   {'name':'Komal','lastname' : 'Bhandari'},
   {'name':'Abdul','lastname' : 'Sattar'},
   {'name':'Priya','lastname' : 'Rajhans'},
])


# Select all
s = students.select()
conn = engine.connect()
result = conn.execute(s)

for row in result:
   print (row)

# Conditional select
s = students.select().where(students.c.id>2)
result = conn.execute(s)

for row in result:
   print (row)


t = text("SELECT * FROM students")
result = connection.execute(t)



### Update
table.update().where(conditions).values(SET expressions)


stmt = students.update().where(students.c.lastname == 'Khanna').values(lastname = 'Kapoor')



### Delete
stmt = students.delete().where(students.c.id > 2)
conn.execute(stmt)

# verify by seeing
s = students.select()
conn.execute(s).fetchall()



## Example
s = select([students, addresses]).where(students.c.id == addresses.c.st_id)
result = conn.execute(s)

for row in result:
   print (row)
