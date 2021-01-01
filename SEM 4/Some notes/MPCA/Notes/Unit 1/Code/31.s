.text
	LDR R0,=a
	LDRH R1, [R0]
	LDR R2,=b
	STRH R1, [R2]

.data
	a: .hword 0xAB56
	b: .hword 0x1234
.end