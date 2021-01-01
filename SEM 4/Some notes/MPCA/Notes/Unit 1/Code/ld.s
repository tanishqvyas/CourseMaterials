.text
ldr r0,=a
ldr r1,=b
ldr r3,=c
ldrb r4,[r1]
ldrb r5,[r0]
add r6,r4,r5
strb r6,[r3]
swi 0x011




.data

a: .byte 10
b: .byte 20
c: .byte 00