global ft_read
extern __errno_location		; using extern function __errno_location

section .text
ft_read:					; rdi == int fd, rsi == char * str, rdx == size_t len
	mov rax,   0			; rax = 0 to specify syscall read
	syscall					; call read
	cmp rax,   0			; compare return value to 0 (stored in rax)
	jl  exit_failure		; if value is inferior to 0 (error caught), jump to exit_failure
	ret

exit_failure:
	neg  rax				; errno takes positive integers so we have to invert sign of rax
	push rax				; save the value of rax that we went to put into errno
	call __errno_location	; __errno_location sets rax to &errno
	pop  rdi				; get the value of rax back and put it into rdi
	mov  [rax], rdi			; assign this value to the variable pointed by rax (errno)
	mov  rax,   -1			; set the return value to EOF (-1)
	ret
