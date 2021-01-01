ldr r0,=a
ldr r1,=b
ldr r2,=c
ldr r3,[r0]
ldr r4,[r1]
ldr r5,[r2]
ldr r6,=d
ldr r7,=e
stmia r6!,{r3,r4,r5}
mov r3,#00
mov r4,#00
mov r5,#00
ldmia r7!,{r3,r4,r5}


.data
a:.word 0x12345678
b:.word 0x98765432
c:.word 0x12212112
d:.word 0,0,0
e:.word 1,2,3