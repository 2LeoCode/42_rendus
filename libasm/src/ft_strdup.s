global ft_strdup
extern malloc					; using extern function malloc

section .text
ft_strdup:						; rsi = char * str
	mov  rcx,             0		; set counter to 0

count:
	inc  rcx					; increment counter before to get length of string + 1
	cmp  BYTE[rdi + rcx], 0		; compare s[counter] to 0
	jne  count					; if not equal then iterate again

alloc:
	push rdi					; save the value of str
	mov  rdi,             rcx	; put the value of counter (length of string + 1) in rdi (first argument)
	push rdi					; save that value before calling the function
	call malloc					; call malloc function with the length + 1 as first parameter
	pop  rcx					; get length + 1 back into rcx
	pop  rsi					; get str back into rsi
	cmp  rax,             0		; check return value of malloc
	je   exit					; if an error occured (malloc returned NULL) jump to exit
	mov  rdi,             rax	; put the allocated memory pointer into rdi

copy:
	cld							; reset direction flags for movsb
	mov  byte[rax + rcx], 0		; set the last byte of the string to 0
	rep  movsb					; corresponds to while (rcx) { *(dst++) = *(src++); rcx--; }

exit:
	ret
