global ft_list_sort

section .text
ft_list_sort:
	push r14
	push r13				; save the value of callee-save registers (calling conventions)
	push r12
	mov  r12,     rsi		; rsi = &cmp, r12 = &cmp
	mov  rdx,     [rdi]		; rdi = &lst, [rdi] = lst, rdx = lst					# initialisation of lst
	mov  r14,     rdx		; rdx = lst, r14 = lst

main_loop:
	cmp  r14,     0			; if (lst == NULL)
	je   exit				; then exit
	mov  r13,     [r14 + 8]	; r14 = lst, [r14 + 8] = lst->next, r13 = lst->next		# initialisation of head_lst
	jmp  sort_loop

main_loop_next:
	mov  rdx,     [r14 + 8] ; r14 = lst, [r14 + 8] = lst->next, rdx = lst->next
	mov  r14,     rdx		; rdx = lst->next, r14 = lst->next, lst = lst->next
	jmp  main_loop

sort_loop:
	cmp  r13,     0			; if (head_lst == NULL)
	je   main_loop_next		; then go back to main loop
	mov  rdi,     [r14]		; r14 = lst, [r14] = lst->data, rdi = lst->data
	mov  rsi,     [r13]		; r13 = head_lst, [r13] = head_lst->data, rsi = head_lst->data
	call r12
	test eax,     eax		; if (lst->data >= head_lst->data)
	js   sort_loop_next		; then continue loop

swap:
	mov  rdx,     [r14]		; r14 = lst, [r14] = lst->data, rdx = lst->data
	mov  r8,      [r13]		; r13 = head_lst, [r13] = head_lst->data, r8 = head_list->data
	mov  [r13],   rdx		; rdx = lst->data, [rpb] = lst->data, head_lst->data = lst->data
	mov  [r14],   r8		; r8 = head_lst->data, [r14] = head_lst->data, lst->data = head_lst->data

sort_loop_next:
	mov  rdx,     [r13 + 8]	; r13 = head_lst, [r13 + 8] = head_lst->next, rdx = head_lst->next
	mov  r13,     rdx		; rdx = head_lst->next, r13 = head_lst, head_lst = head_lst->next
	jmp  sort_loop

exit:
	pop  r12
	pop  r13
	pop  r14				; restore the initial value of callee-save registers
	ret
