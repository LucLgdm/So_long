# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 12:24:12 by lde-merc          #+#    #+#              #
#    Updated: 2025/01/03 10:09:41 by lde-merc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = libft/libft.a
MLX_LIB = mlx/libmlx.a
MLX_FLAGS = -I mlx -Lmlx -lmlx -lX11 -lXext
SRC_DIR = srcs
OBJ_DIR = objs
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCLUDES = includes/

all: makelibft makemlx $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
		$(CC) $(CFLAGS) $(OBJ) -lm $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
		@echo "Creation of the executable $(NAME)"
		
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean
	@make -C mlx clean
	@echo "Cleaning of the object directory $(OBJ_DIR) and libft"
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(MLX_LIB)
	@echo "Cleaning of the executable $(NAME) and the library $(LIBFT)"
	
re: fclean all
	
makelibft:
	make -C libft all

makemlx:
	make -C mlx all

.PHONY: all clean fclean re makelibft makemlx