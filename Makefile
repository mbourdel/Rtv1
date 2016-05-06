# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/19 14:05:23 by mbourdel          #+#    #+#              #
#*   Updated: 2016/05/06 16:20:02 by mbourdel         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = Rtv1

SRC = rtv1.c \
	  get_next_line.c \
	  pixel_put_img.c \
	  touch_the_sphere.c \
	  ray.c \
	  item.c \
	  vector.c \
	  parser.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

MLX = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

L_MLX = minilibx/libmlx.a -lXext -lX11

MLX_PATH = ./minilibx_macos/

L_MLX_PATH = ./minilibx/

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

noflag:
	@echo "No Flag mod"
	@cd $(LIBFT_PATH); $(MAKE) -f Makefile
	@cd $(MLX_PATH); $(MAKE) -f Makefile
	@gcc -c $(SRC)
	@gcc $(OBJ) -o $(NAME) $(LIBFT_PATH)libft.a $(MLX)
	@echo "[================]"
	@echo "|     succes !   |"
	@echo "|      Rtv1      |"
	@echo "|  was summoned  |"
	@echo "[================]"

linux:
	@cd $(LBFT_PATH); $(MAKE) -f Makefile
	@cd $(L_MLX_PATH); $(MAKE) -f Makefile
	@gcc -0fast -c $(SRC)
	@gcc $(OBJ) -o $(NAME) $(LIBFT_PATH)libft.a $(L_MLX)
	@echo "TATATATATATAT"
