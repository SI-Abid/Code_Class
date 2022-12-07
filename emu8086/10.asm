; 10
.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Enter first number: $"
MSG2 DB "Enter second number: $"
MSG3 DB "Enter third number: $"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    LEA DX,MSG1
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H
    MOV BL,AL

    ;NEWLINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H

    LEA DX,MSG2
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H
    MOV CL,AL

    ;NEWLINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H

    LEA DX,MSG3
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H
    MOV BH,AL

    ;NEWLINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H

    CMP BL,CL
    JGE COND1
    JMP COND2
    COND1:
        CMP BL,BH
        JGE A
        JMP C
    COND2:
        CMP CL,BH
        JGE B
        JMP C
    A:
        MOV AH,2
        MOV DL,BL
        INT 21H
        JMP EXIT
    B:
        MOV AH,2
        MOV DL,CL
        INT 21H
        JMP EXIT
    C:
        MOV AH,2
        MOV DL,BH
        INT 21H
        JMP EXIT
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
