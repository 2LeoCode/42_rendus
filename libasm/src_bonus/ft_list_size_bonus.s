global ft_list_size

section .text
ft_list_size:				; rdi == t_list * list
	mov rcx, 0				; set the counter to 0

count:
	cmp rdi, 0				; check if list is NULL
	je  exit				; if so jump to exit
	inc rcx					; else increment counter
	mov rdx, [rdi + 8]		; corresponds to rdx = list->next
	mov rdi, rdx			; then list = rdi (in 2 steps because we can't assign a register to itself)
	jmp count				; iterate again

exit:
	mov rax, rcx			; set the return value to our counter
	ret
