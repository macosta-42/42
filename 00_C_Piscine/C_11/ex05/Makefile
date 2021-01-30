# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 13:29:05 by macosta           #+#    #+#              #
#    Updated: 2020/02/26 11:56:15 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= do-op

SRCS		= fonctions.c main.c operations.c calc.c

OBJS		= ${SRCS:.c=.o}

CC			= cc

INCLUDES	= ft.h

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			
re:			fclean all

.PHONY:		re fclean clean all
