global ft_write
extern __errno_location		; using extern function __errno_location

section .text:
ft_write:					; rdi == int fd, rsi == char * buf, rdx == size_t len
	mov  rax,   1			; set rax to 1 to specify syscall write
	syscall					; then call write
	cmp  rax,   0			; check the return value
	jl   exit_failure		; if an error occured go to exit_failure
	ret

exit_failure:
	neg  rax				; set our return value to a positive value
	push rax				; save that value
	call __errno_location	; call __errno_location to get a pointer to errno
	pop  rdi				; ger back our return value into rdi
	mov  [rax], rdi			; assign that value to errno using the pointer we got
	mov  rax,   -1			; set the return value to EOF (-1)
	ret
