import sqlite3

conn = sqlite3.connect("employee.db")

c = conn.cursor()

# Executing sql commands
c.execute("""CREATE TABLE employees (

			first text,
			last text,
			pay integer

	) """)



# Adding data to database
c.execute("INSERT INTO employees VALUES('Corey', 'Schafer', 500000)")


# c.execute("""SELECT * FROM employees WHERE last='Schafer'""")
# l = c.fetchone()
# l = c.fetchmany(5)
# l = c.fetchall()
# print(l)

# Commits the current transaction
conn.commit()

# Clsoing the connection
conn.close()