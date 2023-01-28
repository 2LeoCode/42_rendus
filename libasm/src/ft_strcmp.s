global ft_strcmp

section .text:
ft_strcmp:						; rdi == char * s1, rsi == char * s2
	mov   al,        BYTE[rdi]	; put value of *s1 to register al (1 byte register)
	cmp   BYTE[rsi], al			; compare this value to *s2
	jne   exit					; if the characters are not the same then jump to exit
	cmp   BYTE[rdi], 0			;
	je    exit					; compare both values to 0
	cmp   BYTE[rsi], 0			; if one of them is equal then jump to exit
	je    exit					;
	inc   rdi					; increment s1 pointer
	inc   rsi					; increment s2 pointer
	jmp   ft_strcmp				; we didn't reach the end so loop again

exit:
	movsx rax,       al			; we use movsx instead of mov to work with different sized registers
	movsx rbx,       BYTE[rsi]	; (we need to put the return value into rax because the function returns an int)
	sub   rax,       rbx		; we set return value to *s1 - *s2
	ret
