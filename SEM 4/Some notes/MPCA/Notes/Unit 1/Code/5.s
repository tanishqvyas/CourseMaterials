.text
	Mov R1, #5
	Mov R2, #7

	Mov R3, R1, LSL #1
	Mov R4, R2, LSL #3
	ADD R5,R1,R1,LSL #2
	RSB R6,R1,R1,LSL #3

	; Multiplication by 6: Multiply by 3, then 2
	ADD R7,R2,R2,LSL #1
	MOV R7,R7,LSL#1

	; Multiply by 10 and add in extra number
	ADD R8,R2,R2,LSL#2 ; multiply by 5
	ADD R8,R1,R8,LSL#1 ; multiply by 2 and add in next digit
	
	MOV R0, R2, ASR #2
	ADD  R9, R1, R2, LSL R3



.end