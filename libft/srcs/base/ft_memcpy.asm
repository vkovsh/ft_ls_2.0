global ft_memcpy
extern _memcpy
	align	16
ft_memcpy:
	push	ebp
	mov	ebp, esp
	push	esi
	push	edi
	mov	edi,[ebp+0x8]	; String s1
	mov	esi,[ebp+0xc]	; String s2
	mov	ecx,[ebp+0x10]	; Length
	; No overlap check here
	jmp	_memcpy	; Call the part of __memmove that copies up