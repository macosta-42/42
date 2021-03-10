# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 14:42:10 by macosta           #+#    #+#              #
#    Updated: 2020/12/05 14:42:36 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global ft_read
	extern __errno_location

ft_read:
	.read:
		mov		rax, 0x0					; rax = read syscall value
		syscall								; syscall read
		cmp		rax, 0						; compare result with 0
		jl		.error						; if result < 0 jump to .error
		ret									; return

	.error:
		neg		rax							; rax = -rax
		push	rax							; save rax
		pop		r12							; use preserved register r12
		call	__errno_location WRT ..plt	; call errno
		mov		[rax], r12					; [rax] = r12 = result
		mov		rax, -1						; rax = -1
		ret									; return
