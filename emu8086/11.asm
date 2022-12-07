.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB "Name: Saiham Islam Abid$"
MSG2 DB "Department: CSE$"
MSG3 DB "Section: E$"
MSG4 DB "Student ID: 2012020207$"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX

    LEA DX,MSG1
    MOV AH,9
    INT 21H
    ;NEWLINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    ;NEWLINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    LEA DX,MSG3
    MOV AH,9
    INT 21H
    ;NEWLINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    LEA DX,MSG4
    MOV AH,9
    INT 21H