global ft_list_remove_if
extern free						; using extern function remuve

; rdx = prev
; rcx = cur
; r8  = head

section .text
ft_list_remove_if:
	push r12
	push r13
	mov  r12,        rdx
	mov  r13,        rcx
	mov  rdx,        0			; prev = NULL
	mov  rcx,        [rdi]		; cur  = *begin_list
	push rdi					; push begin_list

list_loop:
	cmp  rcx,        0			; if cur == NULL exit the function
	je   exit
	mov  r8,         [rcx + 8]	; head = cur->next
	mov  rdi,        [rcx]		; rdi = cur->data
	push rdx
	push rcx
	push r8
	push rdi
	push rsi
	call r12					; cmp rdi, data_ref
	pop  rsi
	pop  rdi
	pop  r8
	pop  rcx
	pop  rdx
	cmp  rax,        0
	je   remove
	mov  rdx,        rcx		; prev = cur

list_loop_next:
	mov  rcx,        r8			; cur = head
	jmp  list_loop

remove:
	push rdx
	push r8
	push rsi
	push rcx
	call r13					; free_fct(cur->data)
	pop  rdi					; rdi = cur
	mov  DWORD[rdi], 0			; cur->data = NULL
	call free					; free(cur)
	pop  rsi
	pop  r8
	pop  rdx
	cmp  rdx,        0			; if prev == NULL jump to move_first
	je   move_first
	mov  [rdx + 8],  r8			; else prev->next = head
	jmp  list_loop_next

move_first:
	pop  rdi					; pop begin_list
	mov  [rdi],      r8			; *begin_list = head
	push rdi					; push begin_list back
	jmp  list_loop_next

exit:
	pop  rdi
	pop  r13
	pop  r12
	ret
