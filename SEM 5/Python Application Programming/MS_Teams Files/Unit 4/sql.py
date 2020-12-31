'''import sqlite3
#connection object
cxn=sqlite3.connect("database.db")
cur=cxn.cursor()
'''
'''cur.execute('create table table1(name char(20),age integer)')
cur.execute('create table table2(name char(20),age integer)')
'''
'''cur.execute('insert into table1 values("rama",30)')
cur.execute('insert into table1 values("kavitha",30)')
cur.execute('insert into table2 values("ramesh",30)')
cur.execute('insert into table2 values("ram",30)')
#usage place holders
info=('manu',10)
cur.execute('insert into table1(name,age) values(?,?)',info)
x=cxn.execute('select * from table1')
for i in x:
	print(i)
'''
'''
#:memory:

import sqlite3
con=sqlite3.connect(":memory:")#create db in ram instead of hard disk
cur=con.cursor()
cur.execute("create table person(name_last,age)")
who="penikalapati"
age=25
cur.execute("insert into person values(?,?)",(who,age))
x=cur.execute('select * from person')
for i in x:
	print(i)
'''

# employee

import sqlite3
conn=sqlite3.connect('company.db')
#print('table created succefully')
#insert
'''conn.execute("insert into employee (empid,name,age,address,salary) values (12,'rama',30,'bangalore',100000)");
conn.execute("insert into employee (empid,name,age,address,salary) values (13,'kavi',30,'bangalore',200000)");
conn.execute("insert into employee (empid,name,age,address,salary) values (14,'rahul',30,'bangalore',300000)");
conn.commit()'''
cursor=conn.execute('select empid,name,salary from employee')
'''for r in cursor:
	print("empid-",r[0])
	print("name-",r[1])
	print("salary-",r[3])'''
conn.execute("update employee set salary=200000 where empid=12")
conn.commit()






















