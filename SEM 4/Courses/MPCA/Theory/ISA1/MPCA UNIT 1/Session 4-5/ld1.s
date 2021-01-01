ldr r0,=a
ldr r1,=b
ldr r3,=c
ldrh r4,[r1]
ldrh  r5,[r0]
add r6,r4,r5
strh  r6,[r3]
swi 0x011


.data

a: .word 0x12345678
b: .word 0x56781234
c: .word 0000 

