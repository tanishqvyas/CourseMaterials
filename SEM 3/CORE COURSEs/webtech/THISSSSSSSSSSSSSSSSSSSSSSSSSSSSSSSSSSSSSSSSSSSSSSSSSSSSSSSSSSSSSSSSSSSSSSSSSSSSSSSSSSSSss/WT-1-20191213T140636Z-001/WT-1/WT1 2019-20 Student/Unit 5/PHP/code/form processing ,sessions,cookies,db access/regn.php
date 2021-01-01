<?php
	//var_dump($_GET);
	
	extract($_GET);
	
	$conn=mysqli_connect("localhost","root","");
	if(!$conn){
		
		die ('connection failed');
		
	}
	mysqli_select_db($conn,"web2019");
	$sql="Insert into USERS values('".$uname."','".$pwd."')";
//$sql="Insert into USERS values('ABC','DEF' )";
	$res=mysqli_query($conn,$sql);
	if(!$res){
		
		die ('query failed');
		
	}
?>