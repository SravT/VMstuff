	global product
	
	section .text


product:

	mov eax, [esp+4]
	mov ecx, [esp+8]
	mov edx, [eax]
	cmp eax, 0
	mov eax, 0
	jle product_done
	cmp ecx, 0
	jle product_done
	
product_loop:
	add eax, edx		
	dec ecx
	cmp ecx, 0
	jg product_loop

product_done:
	ret 

	power:
	mov eax, [esp+4]
	mov ecx, [esp+8]
	mov edx, eax
	cmp ecx, 0
	jnle L1
	jmp power_end

L1:
	dec ecx
	push eax
	call power
	add esp, 4
	imul eax, [esp+4]
power_end:	
	ret

