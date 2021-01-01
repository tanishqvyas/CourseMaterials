; A[2,1]
.text
	LDR R0,=a
	LDR R1, [R0]
	
	LDR R2,=b
	LDR R3, [R2]
	
	LDR R4,=c
	LDR R5, [R4]	
	
	LDR R6,=d
	LDR R7, [R6]
	
	UMULL R9,R8,R1,R3


.data
	a: .word 0xABCD1234
	b: .word 0x12345678
	c: .word 0x1A2B3C4D
	d: .word 0x11223344
.end