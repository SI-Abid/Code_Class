; 12
.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
    MOV BL,30H
    LABEL:
        CMP BL,39H
        JG EXIT
        MOV AH,2
        MOV DL,BL
        INT 21H
        INC BL
        JMP LABEL
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
