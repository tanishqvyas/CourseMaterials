<!DOCTYPE html>
<html>
	<head>
	<script>
		function getData(){
			xhr=new XMLHttpRequest();
			xhr.onreadystatechange=showData;
			xhr.open("GET","http://localhost/web1/abc.txt",true);
			xhr.send();
			
		}
		function showData(){
			if(xhr.readyState==4 && xhr.status==200){
			
			document.getElementById("text").innerHTML=xhr.responseText;
			}
			//console.log(xhr.readyState);
			//console.log(xhr.responseText);
		}
	</script>
	
	</head>
	<body>
		<input type="text" id="uname" name="uname" onblur="checkUser()"/>
		
		<div id="msg"></div>
		<p>
		Our server, router, and request handlers are in place, thus now we can begin to add content to our
site which allows our users to interact and walk through the use case of choosing a file, uploading
this file, and viewing the uploaded file in the browser. For the sake of simplicity we will assume that
only image files are going to be uploaded and displayed through the application.
Ok, let’s take it step by step, but with most of the techniques and principles of JavaScript explained
by now, let’s at the same time accelerate a bit. This author likes to hear himself talking way too
much anyways.
Here, step by step means roughly two steps: We will first look at how to handle incoming POST
requests (but not file uploads), and in a second step, we will make use of an external Node.js module
for the file upload handling. I’ve chosen this approach for two reasons.
First, handling basic POST requests is relatively simple with Node.js, but still teaches us enough to
be worth exercising it.
Second, handling file uploads (i.e., multipart POST requests) is not simple with Node.js, and therefore
is beyond the scope of this tutorial, but using an external module is itself a lesson that makes sense
to be included in a beginner’s tutorial.
		
		</p>
	</body>



</html>     