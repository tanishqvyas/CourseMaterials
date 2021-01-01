.text
	LDR R0,=a
	LDRB R1, [R0]
	LDR R2,=b
	STRB R1, [R2]

.data
	a: .byte 0xAB
	b: .byte 0x12
.end