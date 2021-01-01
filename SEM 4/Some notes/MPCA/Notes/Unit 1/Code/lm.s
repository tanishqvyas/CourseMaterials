

ldr r0,=a
ldr r4,=b
stmia r0,{r1,r2,r3}
ldmia r4!,{r1,r2,r3}
.data
a: .word 0x12345678
b: .word 0x55555555
c: .word 0x12345643
d: .word 0x12222222
e: .word 0x12345678