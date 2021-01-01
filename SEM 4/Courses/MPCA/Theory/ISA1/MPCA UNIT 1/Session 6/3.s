.text
	LDR R0,=a
	LDMIB R0 !,{R1-R3}

.data
	a: .word 0xABCD1234
	b: .word 0x12345678
	c: .word 0x1A2B3C4D
	d: .word 0x11223344
.end