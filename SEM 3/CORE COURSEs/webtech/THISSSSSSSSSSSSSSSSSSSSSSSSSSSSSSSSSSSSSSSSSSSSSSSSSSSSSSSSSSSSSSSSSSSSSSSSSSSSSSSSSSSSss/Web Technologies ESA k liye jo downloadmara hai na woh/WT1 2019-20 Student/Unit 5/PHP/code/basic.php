<?php

//This is a single line comment
/*This is not a single line comment
This is a not single line comment*/
//Output
$a=5;
echo $a++;
echo $a;
$a+=9;
echo $a;
echo "hello";
print "i am also an\n output function my value is $a";
print 'i am also an\n output function my value is $a';
print "in PHP the variable are prefixed with a $ as in \$a";
echo "sting concatenation is done".$a;
$a="";
if($a===0){
	echo "equal";
	echo "<br>";
	
}

else if($a>0)
{
	echo "greater";
}

else {
	
	echo "not equal";
}
if($a){
	
	echo "home";
	
}
else {
	echo "class";
}
echo (12/6);
echo (12/5);

echo floor(7.8);

?>