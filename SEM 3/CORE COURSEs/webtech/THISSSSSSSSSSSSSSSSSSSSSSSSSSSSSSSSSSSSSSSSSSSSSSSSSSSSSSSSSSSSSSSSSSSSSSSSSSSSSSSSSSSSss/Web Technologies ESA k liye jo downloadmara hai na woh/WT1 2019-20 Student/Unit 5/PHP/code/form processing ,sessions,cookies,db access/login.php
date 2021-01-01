<?php
	session_start();
	extract($_POST);
	$conn=mysqli_connect("localhost","root","");
	if(!$conn){
		
		die ('connection failed');
		
	}
	mysqli_select_db($conn,"web2019");
	                               
	$query="Select * from users;";
	$res=mysqli_query($conn,$query);
	if(!$res){
		
		die('query failed');
	}
	else{
		
		while($row=mysqli_fetch_assoc($res)){
		if($row["user"]==$uname && $row["pwd"]==$pwd){
			echo "valid user";
			$_SESSION["user"]=$uname;
			exit;
		}
		
		
	}
	echo "invalid user";	
		
	}
	
?>