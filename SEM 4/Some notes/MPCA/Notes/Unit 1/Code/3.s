.text
	Mov R0, #4
	Mov R1, #5
	Mov R2, #3
	Mov R3, #8

	SUBS R4, R1, R3
	SBC R5, R0, R2
	SUBS R6, R0, R2
	RSB R9, R1, R3
	
	ADDS R7, R2, R3
	ADC R8, R0, R1
.end