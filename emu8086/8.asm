.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Enter a number: $"
MSG2 DB "Enter another number: $"
MSG3 DB "FIRST NUMBER IS BIGGER$"
MSG4 DB "SECOND NUMBER IS BIGGER$"
MSG5 DB "BOTH ARE EQUAL$"
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

    CMP BL,CL
    JG BORO
    JL COTO
    
    SOMAN:
        LEA DX,MSG5
        MOV AH,9
        INT 21H
        JMP EXIT
    
    BORO:
        LEA DX,MSG3
        MOV AH,9
        INT 21H
        JMP EXIT
    
    COTO:
        LEA DX,MSG4
        MOV AH,9
        INT 21H
        JMP EXIT
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
