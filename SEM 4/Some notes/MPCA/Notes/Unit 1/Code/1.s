.text
	LDR R0,=a
	MOV R3, #4
	
	LDR R1,[R0,#4]
	LDR R2,[R0,#4]
	
	LDR R4,[R0,#4]!
	LDR R5,[R0,#4]!
	
	LDR R6,[R0,R3]!
	LDR R7,[R0,R3,LSR #3]
	LDR R8, [R0],#4
	LDR R9,[R0],#4

.data
	a: .word 10,20,30,40,50,60
.end
