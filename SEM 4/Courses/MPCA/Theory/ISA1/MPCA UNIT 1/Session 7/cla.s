ldr r4,=a
mov r1,#24
mov r2,#25
stmfd r13!,{r1,r2}
bl LINK
str r0,[r4]
swi 0x11
LINK: ldmfd r13!,{r4,r5}
add r0,r4,r5
mov pc,lr

a:.word 0

.end
