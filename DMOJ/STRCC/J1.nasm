section .text
global _start

_start:
        mov     eax,    4
        xor     ebx,    ebx
        inc     ebx
        mov     ecx,    msg
        mov     edx,    len
        int     80h

        xor     eax,    eax
        inc     eax
        xor     ebx,    ebx
        int     80h

section .data
        msg     db      "HELLO ST. ROBERTS!", 0xA
        len     equ     $ - msg
