EXTERN syscallHandler
GLOBAL _readLine

_readLine:
	push rbp
	mov rsp, rbp
	mov rdi, 0   ;Id de readLine
	call syscallHandler
	mov rsp, ebp
	push rbp
	ret