.MODEL SMALL
.DATA
    msg1 db 0ah,0dh,'Enter the string:','$'
    msg2 db 0ah,0dh,'It is palindrome','$'
    msg3 db 0ah,0dh,'It is not a palindrome','$'
    n db 09h dup(?)

.CODE
START:
    mov ax,@data
    mov ds,ax
    
    mov di,offset n
    mov si,offset n

    lea dx,msg1
    mov ah,09h
    int 21h

    mov cl,00h

scan:
    mov ah,01h
    int 21h

    cmp al,0dh
    je ended
    mov [si],al
    inc cl
    inc si
    jmp scan

ended:
    dec si
    mov bl,[si]
    cmp [di],bl
    jne notpal
    inc di
    dec cl
    jne ended

pal:
    lea dx,msg2
    mov ah,09h
    int 21h
    jmp stopped

notpal:
    lea dx,msg3
    mov ah,09h
    int 21h

stopped:
    mov ah,02h
    int 21h

.EXIT
END START
