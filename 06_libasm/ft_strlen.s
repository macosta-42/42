# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/05 14:43:49 by macosta           #+#    #+#              #
#    Updated: 2020/12/05 14:43:51 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strlen

ft_strlen:
	xor		rax, rax				; init rax = 0

	.count:
		cmp		BYTE [rdi + rax], 0 ;
		je		.exit				; if (rdi[rax] == 0) then exit
		inc		rax					; rax++
		jmp		.count				; jump count

	.exit:
		ret							; return rax
