<?php
	session_start();
	if(isset($_SESSION["user"])){

	echo "this page should be displayed only when you are logged in";
	
	echo "<br/> <a href='logout.php'>Logout</a>";
	}
	else{
		
		echo "login required";
	}

?>