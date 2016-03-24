# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/19 14:05:23 by mbourdel          #+#    #+#              #
#    Updated: 2016/03/24 12:36:28 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Rtv1

SRC = rtv1.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

MLX = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

MLX_PATH = ./minilibx_macos/

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@cd $(LIBFT_PATH); $(MAKE) -f Makefile
	@cd $(MLX_PATH); $(MAKE) -f Makefile
	@gcc -c $(FLAG) $(SRC)
	@gcc $(FLAG) $(OBJ) -o $(NAME) $(LIBFT_PATH)libft.a $(MLX)
	@echo "[================]"
	@echo "|     succes !   |"
	@echo "|      Rtv1      |"
	@echo "|  was summoned  |"
	@echo "[================]"

clean:
	@rm -rf $(OBJ)
	@echo "[================]"
	@echo "|     succes !   |"
	@echo "|     XXXXX.o    |"
	@echo "|  was destroyed |"
	@echo "[================]"

fclean: clean
	@rm -rf $(NAME)
	@echo "[================]"
	@echo "|     succes !   |"
	@echo "|      Rtv1      |"
	@echo "|  was destroyed |"
	@echo "[================]"

re: fclean all

deslib:
	@cd $(LIBFT_PATH); $(MAKE) fclean -f Makefile
	@cd $(MLX_PATH); $(MAKE) clean -f Makefile

total: deslib re

