mov r0,#10
mov r1,#20
mov r2,#30
mov r3,#40
mov r4,#50
mov r5,#60
mov r6,#70
mov r7,#80
loop: ldmia r10!,{r0-r7}
stmia r10!,{r0-r7}
cmp r9,r11
bne loop