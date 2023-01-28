global ft_atoi_base

section .bss
n:  resq 1									; allocate QWORD (8 bytes)
ng: resq 1									; allocate QWORD (8 bytes)
b:  resd 1									; allocate DWORD (4 bytes)
bi: resd 1									; allocate DWORD (4 bytes)

section .text
ft_strchr:
	cmp BYTE[rdi],    sil
	je  ft_strchr_exit_true
	cmp BYTE[rdi],    0
	je  ft_strchr_exit_false
	inc rdi
	jmp ft_strchr

ft_strchr_exit_true:
	mov rax,          rdi
	ret

ft_strchr_exit_false:
	mov rax,          0
	ret

ft_isspace:
	cmp dil,              32
	je  ft_isspace_exit_success
	cmp dil,              9
	je  ft_isspace_exit_success
	cmp dil,              10
	je  ft_isspace_exit_success
	cmp dil,              11
	je  ft_isspace_exit_success
	cmp dil,              12
	je  ft_isspace_exit_success
	cmp dil,              13
	je  ft_isspace_exit_success
	mov rax,              0
	ret

ft_isspace_exit_success:
	mov  rax,             1
	ret

check_base:									; rdi = pointer to base
	mov  rcx,             0					; set our counter to 0

check_base_loop:
	cmp  BYTE[rdi + rcx], 0					; check end of string
	je   check_base_exit					; if it's the end jump to check_base_exit
	cmp  BYTE[rdi + rcx], '-'				; check if character is '-'
	je   invalid_base						; if so, it's an invalid base
	cmp  BYTE[rdi + rcx], '+'				; same for '+'
	je   invalid_base						;
	push rdi
	push rcx
	mov  bl,              BYTE[rdi + rcx]	; put current character into byte register bl
	mov  dil,             bl				; then put it in dil (first argument)
	call ft_isspace							; check if current character is space
	pop  rcx								; pop back from the stack before checking return value
	pop  rdi								;
	cmp  rax,             0					; check return value of ft_isspace
	jne  invalid_base						; if it's not equal to 0, it's an invalid base, it contains a space
	mov  sil,             BYTE[rdi + rcx]	; put current character into byte register sil
	inc  rcx								; increment counter
	push rdi
	push rcx
	add  rdi,             rcx				; increment the base pointer to get to the position of the next character
	call ft_strchr							; check if a character is present two times by searching for this character
	pop  rcx								;  inside the string from after the current character
	pop  rdi								; then we get back the original value of the base pointer
	cmp  rax,             0					; if ft_strchr returns NULL
	je   check_base_loop					; then we can continue, or else we keep going to invalid_base

invalid_base:
	mov  rax,				0				; set the return value to 0 for an invalid_base
	ret

check_base_exit:
	mov  rax,				rcx				; set the return value to the size of the base
	ret

ft_atoi_base:								; rdi == char * str, rsi == char * base
	mov  QWORD[n],			0				; set our number to 0
	mov  QWORD[ng],			1				; set negation variable to "positive"
	push rsi
	push rdi
	mov  rdi,				rsi				; put base to first argument
	call check_base							; call check_base
	pop  rdi
	pop  rsi
	cmp  rax,				0				; check return of check_base
	je   exit								; if wrong base jump to exit
	mov  [b],				rax				; store the base size to b
	push rsi								; we save rsi here because we'll call a bunch of function and we don't need it for now

skip_spaces:
	push rdi								; we save rdi here because we'll need it in this loop after the function call
	mov  cl,				BYTE[rdi]		; put the first byte of the number string into byte register cl
	mov  dil,				cl				; we put it in first function argument dil after because we can't move it directly from rdi to dil
	call ft_isspace
	pop  rdi
	cmp  rax,				0				; check return value of ft_isspace
	je   skip_signs							; if character is not space then jump to the next step
	inc  rdi								; else increment the pointer to the number string
	jmp  skip_spaces						; and loop again

skip_signs:
	cmp  BYTE[rdi],			'+'				; check if current character is '+'
	je   skip_char							; if so jump to skip_sign
	cmp  BYTE[rdi],			'-'				; now check if current character is '-'
	je   neg_n								; if so jump to neg_n (then go through skip_sign)
	pop  rsi								; now we'll need the value of the base string so we pick it back
	jmp  ft_atoi_base_loop					; and we jump into the main loop

neg_n:
	neg  QWORD[ng]

skip_char:
	inc  rdi								; we skip the current character by incrementing the pointer
	jmp  skip_signs							; and we go back to skip_signs loop to see if there are other signs

ft_atoi_base_loop:
	cmp  BYTE[rdi],			0				; we check if the string still contains something after skipping spaces/signs
	je   exit								; if not we jump to exit
	mov  rax,				[ng]			; set the rax to the negation variable
	push rdi
	push rsi
	mov  cl,				BYTE[rdi]		; put the str pointed byte to cl
	mov  rdi,				rsi				; put the base pointer to rdi (first argument)
	mov  sil,				cl				; then put cl (*str) to sil (second argument)
	call ft_strchr							; call ft_strchr(*str, base)
	pop  rsi
	pop  rdi
	cmp  rax,				0				; check return value after popping stack data
	je   exit								; if ft_strchr returns NULL, the character is not in the base, exit
	sub  rax,				rsi				; get the index of the character in base into rax by doing base - return of ft_strchr
	mov  [bi],				rax				; store it into memory in variable bi
	mov  rax,				[n]				; put number in rax (0 at beginning)
	imul QWORD[b]							; multiply rax by the size of the base
	add  rax,				[bi]			; then add the index of the character in base
	mov  [n],				rax				; and store it back to memory
	inc  rdi								; increment str pointer
	jmp  ft_atoi_base_loop					; and iterate again

exit:
	mov  rax,				[n]				; set the return value to the number
	imul QWORD[ng]							; multiply it by the negation variable (we are using QWORD (which corresponds to long) so no int overflow)
	ret
