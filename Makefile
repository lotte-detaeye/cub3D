# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 15:17:42 by lde-taey          #+#    #+#              #
#    Updated: 2025/01/03 16:25:34 by lde-taey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Werror -Wall -Wextra #-fsanitize=address

CC = cc

MLX = minilibx-linux/libmlx.a #-Lminilibx-linux -lmlx_Linux

SRCS = srcs/main.c \
	srcs/calculate_distance.c \
	srcs/cleanup.c \
	srcs/init.c \
	srcs/init_mlx.c \
	srcs/player_movement.c \
	srcs/ray_caster.c \
	srcs/ray_caster_axis.c \
	srcs/ray_caster_zones.c \
	srcs/casting.c \
	srcs/find_horizontal_wall.c \
	srcs/find_vertical_wall.c \
	srcs/errors.c \
	srcs/errors_2.c \
	srcs/minimap.c \
	srcs/minimap_tools.c \
	srcs/minimap_tools_frame.c \
	srcs/parse_checks.c \
	srcs/parse_checks_tools.c \
	srcs/parse_colors.c \
	srcs/parse_floodfill.c \
	srcs/parse_floodfill_tools.c \
	srcs/parse_input.c \
	srcs/parse_map.c \
	srcs/parse_map_tools.c \
	srcs/parse_textures.c \
	srcs/parse_utils.c \
	srcs/parse_store_paths.c \
	srcs/render.c \
	srcs/player_turns.c \
	srcs/get_grid_position.c \
	srcs/set_textures.c 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C minilibx-linux
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) $(MLX) -lX11 -lXext -lm

all : $(NAME)

.PHONY : clean fclean re

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
