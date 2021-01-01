.TEXT
       LDR R4, =a
       MOV  R1, #25
       MOV  R2, #25
       STMFD R13!, {R1, R2}
	   BL  LINK
	   STR R0, [R4]
       SWI 0x11

LINK:  LDMFD R13!,{ R5, R6} 
       ADD R0, R5, R6
       MOV PC, LR
.DATA		  
   a: .WORD  12
.END
