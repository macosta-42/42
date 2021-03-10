# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macosta <macosta@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 07:00:13 by macosta           #+#    #+#              #
#    Updated: 2020/11/07 06:26:05 by macosta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D
MLX	= -lX11 -lXext -lm -lbsd
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I./includes
RM	= rm -f

SRCS	= cub3d.c srcs/init/init_game.c  srcs/init/mapformat_checker.c \
		srcs/init/init_utils.c srcs/init/resolution_collect.c \
		srcs/init/color_collect_utils.c srcs/init/texture_collect.c \
		srcs/init/color_collect.c srcs/init/player_position_collect.c \
		srcs/init/sprite_position_collect.c srcs/init/map_collect.c \
		srcs/frame/wall_raycasting.c srcs/frame/fillin_image.c \
		srcs/frame/sprite_raycasting_utils.c srcs/frame/background.c \
		srcs/frame/frame_utils.c srcs/frame/screenshot.c \
		srcs/frame/sprite_raycasting.c srcs/manager/loop_manager.c \
		srcs/manager/free_manager.c srcs/manager/key_manager.c \
		srcs/manager/error_manager.c srcs/manager/window_manager.c \
	   	srcs/engine/textures.c srcs/engine/player.c srcs/engine/camera.c \

OBJS	=	${SRCS:.c=.o}

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	${OBJS}
			make all -C ./lib/minilibx
			make all -C ./lib/libft

			$(CC) -o $(NAME) $(OBJS) -L./lib/minilibx -lmlx ./lib/libft/libft.a $(MLX)

all:		${NAME}

bonus:		${OBJS} ${OBJSBONUS}
			ar rc ${NAME} ${OBJS} ${OBJSBONUS} 

clean:
			make clean -C ./lib/minilibx 
			make clean -C ./lib/libft
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			make fclean -C ./lib/libft
			${RM} ${NAME}

re:			fclean all

.PHONY:	all libft.a clean fclean re libmlx.a
