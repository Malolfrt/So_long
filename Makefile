# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 16:37:57 by mlefort           #+#    #+#              #
#    Updated: 2024/02/26 18:54:40 by mlefort          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC 		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
# contains the X and MLX headers files #
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib -lXext -lX11

OBJ_PATH = ./src/obj/
SRC_PATH = ./src/

SRC_FILES	=	so_long.c \
				check_map.c \
				get_next_line.c \
				get_next_line_utils.c \
				so_long_utils.c \
				get_map.c \
				main.c \
				flood_file_map.c \
				flood_file_utils.c \
				map_init.c \
				so_long_init.c \
				mouvement.c \
				ft_printf.c \
				ft_printf_utils.c \
				so_long_finish.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: mlx $(OBJ_PATH) $(NAME)

mlx:
	@$(MAKE) -C mlx/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
		mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)


clean:
	rm -rf *.o $(OBJ_PATH)
	@$(MAKE) -C mlx clean


fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C mlx fclean

re: clean all

.PHONY: all clean fclean re mlx