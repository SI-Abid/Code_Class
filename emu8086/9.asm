; 9
.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Enter a number: $"
MSG2 DB "IN RANGE [3-8]$"
MSG3 DB "NOT IN RANGE [3-8]$"
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

    CMP BL,33H
    JGE CHECK
    JMP NIR

    CHECK:
        CMP BL,38H
        JLE IR
        JMP NIR
    NIR:
        LEA DX,MSG3
        MOV AH,9
        INT 21H
        JMP EXIT
    IR:
        LEA DX,MSG2
        MOV AH,9
        INT 21H
        JMP EXIT
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
