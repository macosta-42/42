# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 14:43:25 by macosta           #+#    #+#              #
#    Updated: 2020/12/05 14:43:27 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_strdup
	extern ft_strlen
	extern malloc
	extern ft_strcpy
	extern __errno_location

ft_strdup:
	.dup:
		push	rdi					; stock rdi = str in the stack
		call	ft_strlen			; len of arg[0] = str into rax
		inc		rax					; rax++ for end of string \0
		mov		rdi, rax			; stock len as arg[0] for malloc call
		call	malloc WRT ..plt	; malloc return address in rax
		cmp		rax, 0				; check malloc fail
		je		.error
		pop		rsi					; take str from stack to arg[1] (rsi/src) for ft_strcpy call
		mov		rdi, rax			; stock rax to arg[0] (rdi/dest) for ft_strcpy call
		call	ft_strcpy			; return address in stack
		ret

	.error:
		call	__errno_location WRT ..plt	; call errno for use in .c files
		xor		rax, rax			; rax = null
		ret
