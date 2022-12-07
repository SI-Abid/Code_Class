.MODEL SMALL
.STACK 100H
.DATA
MSG DB "Enter a ALPHABET: $"
VAR1 DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,MSG
    INT 21H
    
    MOV AH,1
    INT 21H
    MOV VAR1,AL
           
    ;CONVERT G -> 7
    SUB VAR2,10H
           
    MOV AH,2
    MOV DL,VAR1
    INT 21H
