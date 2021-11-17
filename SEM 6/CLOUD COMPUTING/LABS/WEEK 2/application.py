from flask import Flask, redirect, url_for, request, jsonify

from flask_mysqldb import MySQL
application=app = Flask(__name__)
mysql=MySQL(app)
app.config['MYSQL_HOST']	 = 'aay7shp7cg6h5t.chsrgddguj0f.us-east-1.rds.amazonaws.com'
app.config['MYSQL_USER']	 = 'PES1201800125'
app.config['MYSQL_PASSWORD'] = 'PES1201800125'
app.config['MYSQL_DB'] 		 = 'PES1201800125'
@app.route("/api/register",methods=["POST"])
def Register_User():
	if(request.method == 'POST'):
		data=request.get_json()
		cur=mysql.connection.cursor()
		Username=data['uname']
		Passwd=data['pswd']
		Mobile=data['mob']
		Age=data['age']
		print(Username,Age)
		try:
			cur.execute("INSERT INTO New_Users(username,password,age,mobile_number) VALUES (%s,%s,%s,%s)",(str(Username),str(Passwd),int(Age),str(Mobile)))
			mysql.connection.commit()
			cur.close()
			return jsonify(),200
		except:
			mysql.connection.commit()
			cur.close()
			return jsonify(),400


@app.route("/api/verify",methods=["POST"])
def Verify_User():
	if(request.method == 'POST'):
		data=request.get_json()
		cur=mysql.connection.cursor()
		Username=data['uname']
		Passwd=data['pswd']
		val=(Username,Passwd)
		query="Select * From New_Users Where username= %s and password= %s"
		try:
			cur.execute(query,val)
			d=cur.fetchall()
			print(d)
			return jsonify(d[0]),200
		except:
			return jsonify(),400




if __name__ == '__main__':
   app.run(debug = True)