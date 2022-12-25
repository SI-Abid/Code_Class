.MODEL SMALL
.STACK 100H
.DATA
MSG DB "Enter an ALPHABET: $"
VAR DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,9
    LEA DX,MSG
    INT 21H
    
    MOV AH,1
    INT 21H
    MOV VAR,AL
           
    ;CONVERT G -> 7
    SUB VAR,10H
           
    MOV AH,2
    MOV DL,VAR
    INT 21H
