# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/12 10:44:15 by macosta           #+#    #+#              #
#    Updated: 2020/06/25 10:24:30 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./srcs/

OBJS = $(SRCS:.c=.o)

SRCS:= $(filter-out ft_lst%.c, $(wildcard srcs/*.c))

INCLUDES = -I./includes

all:	lib $(NAME)

lib:
	@make -C libft/ all

$(NAME): $(OBJS)
	ar rcs $(NAME) $^ libft/*.o

$(OBJS) : $(HEADERS)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
			rm -f $(OBJS)
			@make -C libft/ clean

fclean: clean
			rm -f  $(NAME)
			@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus lib
