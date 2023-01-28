%define SIZE_LIST 16
; the list we are using contains two pointers, size of a pointer is 8, so size = 8 * 2 = 16

global ft_list_push_front
extern malloc					; using extern function malloc

section .text
ft_list_push_front:				; rdi == t_list ** list_ptr, rsi == void * content
	push rdi					; save the value of list_ptr
	push rsi					; save the value of content
	mov  rdi,       SIZE_LIST	; set first argument to SIZE_LIST
	call malloc					; call malloc with argument SIZE_LIST
	pop  rsi					; get value of content back in rsi
	pop  rdi					; same for list_ptr
	cmp  rax,		0			; check return value of malloc 
	je   exit					; if an error occured then jump to exit
	mov  [rax],     rsi			; else move content into the allocated list
	mov  rdx,       [rdi]		; sets rdx to *list_ptr
	mov  [rax + 8], rdx			; set allocated_list->next to rdx (+8 is because next pointer is after content pointer so at 8 bytes from beggining)
	mov  [rdi],     rax			; *list_ptr = allocated_list

exit:
	ret
