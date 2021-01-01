; A[2,1]
.text
	LDR R0,=a
	LDR R1, [R0]
	MOV R2, #2
	MOV R3, #3
	MOV R4, #1
	MLA R5, R2,R3,R4
	LDR R6, [R0, R5, LSL #2]

.data
	a: .word 10,20,30,40,50,60,70,80,90
.end