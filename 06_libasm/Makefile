# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 04:08:42 by macosta           #+#    #+#              #
#    Updated: 2020/12/05 13:13:09 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
SRCS		=	ft_strlen.s\
					ft_strcpy.s\
					ft_strcmp.s\
					ft_write.s\
					ft_read.s\
					ft_strdup.s
OBJ			=	$(SRCS:.s=.o)
HEADER		=	libasm.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NASM		=	nasm
NASMFLAGS	=	-f elf64
TEST		=	test

%.o:			%.s
					$(NASM) $(NASMFLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJ)
					ar rcs $(NAME) $(OBJ) $(HEADER)
clean:
				rm -rf $(OBJ)

fclean:			clean
					rm -rf $(NAME) $(TEST)

re:					fclean $(NAME)

test:			$(NAME)
				$(CC) $(CFLAGS) -o $(TEST) main.c $(NAME)

.PHONY:			all clean fclean re test