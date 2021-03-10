# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 14:43:06 by macosta           #+#    #+#              #
#    Updated: 2020/12/05 14:43:11 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcpy

ft_strcpy:
	xor		rcx, rcx				; init rcx = 0

	.copy:
		cmp		BYTE [rsi + rcx], 0	;
		je		.exit				; if rsi[rcx] == 0 jump to function exit
		mov		dl, [rsi + rcx]		; dl = rsi[rcx]
		mov		[rdi + rcx], dl		; rdi[rcx] = dl
		inc		rcx					; rcx++
		jmp		.copy				; jump to copy function

	.exit:
		xor		dl, dl				; dl = 0
		mov		[rdi + rcx], dl		; rdi[rcx] = dl
		xor		rax, rax			; init rax = 0
		mov		rax, rdi			; rax = rdi
		ret
