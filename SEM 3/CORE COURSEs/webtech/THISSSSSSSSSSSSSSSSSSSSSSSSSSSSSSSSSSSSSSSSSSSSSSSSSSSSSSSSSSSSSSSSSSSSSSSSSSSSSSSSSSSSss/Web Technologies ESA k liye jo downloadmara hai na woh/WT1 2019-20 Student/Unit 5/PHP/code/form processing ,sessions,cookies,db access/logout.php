<?php
	session_start();  
	if(isset($_SESSION["user"])){
	
		session_destroy();
	}
	echo "user logged out";


?>