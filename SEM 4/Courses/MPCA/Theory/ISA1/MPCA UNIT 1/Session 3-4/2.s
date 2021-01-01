.text	
	MOV R0, #4
	MOV R1, #5
	MOV R2, #3
	MOV R3, #7
	
	MVN R4,R3
	CMP R3,R1
 	CMN R3,R1
	TST R1,R0
	TEQ R1,R2
.end