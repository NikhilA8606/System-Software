.model small
.386
.data
    array dd 30 dup(?)
    len db ?
    temp dd ?
    str1 db 0ah,"Enter the number of elements: $"
    str2 db 0ah,"Enter the array elements: $"
    str3 db 0ah,"The sorted array is $"
    
.code
    mov ax,@data
    mov ds,ax
    
    lea dx,str1
    mov ah,09h
    int 21h
    
    mov ah,01h
    int 21h
    sub al,30h
    mov [len],al
    
    lea dx,str2
    mov ah,09h
    int 21h
    
    lea si,array
    mov cl,[len]
    read:
        mov ebx,0000h
        mov ah,01h
        int 21h
        mov bh,al
        
        int 21h
        mov bl,al
        
        rol ebx,16
        
        int 21h
        mov bh,al
        
        int 21h
        mov bl,al
    
        mov [si],ebx
        add si,4
        mov ah,02h
        mov dl," "
        int 21h
    loop read
    
    lea si,array
    mov cl,[len]
    ; Using Bubble Sort
    sort:
        lea si,array
        mov bh,[len]
        .while bh > 1
            mov eax,[si]
            .if eax > [si+4]
                mov [temp],eax
                mov eax,[si+4]
                mov [si],eax
                mov eax,[temp]
                mov [si+4],eax
            .endif
            add si,4
            dec bh
        .endw
    loop sort
    
    lea dx,str3
    mov ah,09h
    int 21h
    
    ;Displaying the sorted array
    lea si,array
    mov cl,[len]
    mov ah,02h
    display:
        mov ebx,[si]
        mov ch,04h
        .while ch > 0
            rol ebx,8
            mov dl,bl
            int 21h
            dec ch
            inc si
        .endw
        mov ah,02h
        mov dl," "
        int 21h
    loop display        
        
    mov ah,4ch
    int 21h
end