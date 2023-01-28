global ft_strcpy

section .text:
ft_strcpy:				; rdi == char * dest, rsi == char * src
	mov rcx,       0	; set counter to 0

copy:
	inc	rcx				; increment counter
	cmp	BYTE[rsi], 0	; check if *src is null
	je	exit			; if so, jump to exit
	cld					; clear direction flags for movsb
	movsb				; corresponds to *(dest++) = *(src++)
	jmp	copy			; jump back to copy

exit:
	movsb				; copy the null byte from src
	sub rdi,       rcx	; substract dest pointer using the counter to get at the beginning
	mov rax,       rdi	; set the return value to dest
	ret
