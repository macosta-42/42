# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/30 10:54:24 by macosta           #+#    #+#              #
#    Updated: 2020/11/06 08:01:56 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCS 		= ft_isalnum.c ft_isascii.c ft_isprint.c ft_strchr.c  ft_strlen.c \
		  	ft_strrchr.c ft_toupper.c ft_isalpha.c ft_isdigit.c ft_memcpy.c \
			ft_strncmp.c ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
			ft_atoi.c ft_memset.c ft_bzero.c ft_memchr.c ft_memccpy.c \
			ft_memmove.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c

BONUS_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

HEADER		= libft.h get_next_line.h

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS} ${HEADER}

all:		$(NAME)

bonus:		${OBJS} ${BONUS_OBJS}
			ar rc $(NAME) ${OBJS} ${BONUS_OBJS}

clean:		
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re
