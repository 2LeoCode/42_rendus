global ft_strlen

section .text
ft_strlen:						; rdi == char * str
	mov rcx, 0					; set counter to 0

count:
	cmp BYTE[rdi + rcx], 0		; compare str[counter] to 0
	je  exit					; if we're at the end go to exit
	inc rcx						; increment counter
	jmp count					; loop again

exit:
	mov rax,             rcx	; put the counter into return value
	ret
