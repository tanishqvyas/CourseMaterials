function vehicletypes()

{
	alert("vehicle booking on")
var transport = document.getElementById("new")
//document.write(transport);
for(var index=0;index<transport.vehicle.length;index++)
{
	if(transport[index].checked )
	{
		variety = transport[index].value}
	
}
switch(variety)
{
	case "car": 
	{
		
	var a=document.getElementById("new")
	a.onsubmit = this.blur	
	document.write("car is booked ")
	document.write("booking amount is non refundable")
	
		break;
	}
	case "bike":alert("bike is booked");break;
	case "truck":alert("truck is booked"); break;
}
return
}

