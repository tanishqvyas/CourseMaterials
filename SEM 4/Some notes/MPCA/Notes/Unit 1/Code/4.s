.text
	Mov R1, #5
	Mov R2, #88
	
	
	ADD R9, R1, R2, ROR  #3
	MOV R0, R2, ASR #2
	ADD  R0, R1, R2, LSL R3

	; Fast multiply R12= 35xR0
 	ADD  R11, R0, R0, LSL #2
 	RSB  R12, R0, R0, LSL #3

 	MUL  R2, R0, R1
	ADD  R0, R0, R0, LSL #2
 	RSB  R2, R0, R0, LSL #3 

.end   
