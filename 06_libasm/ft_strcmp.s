# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 14:42:47 by macosta           #+#    #+#              #
#    Updated: 2020/12/05 14:42:51 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcmp

ft_strcmp:
	.compare:
		movzx rax, byte [rdi]	; init rax and rax = rdi
		movzx rdx, byte [rsi]	; init rdx and rdx = rsi
		sub rax, rdx			; rax = rax - rdx if 0 ZF = 1 else ZF = 0
		jnz .exit				; if ZF = 0 jump to .exit
		cmp byte [rdi], 0		; 
		je .exit				; if rdi = 0 jump to .exit
		inc rdi					; rdi++
		inc rsi					; rsi++
		jmp .compare			; loop
	.exit:
		ret						; return rax = rax - rdx
