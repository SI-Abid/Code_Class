.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
    MOV AH,2
    MOV DL,40H
    INT 21H
    MOV DL,2AH
    INT 21H
    MOV DL,25H
    INT 21H
    MOV DL,24H
    INT 21H
    MOV DL,23H
    INT 21H  
    MOV DL,40H
    INT 21H