# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/12 18:06:02 by mbourdel          #+#    #+#              #
#    Updated: 2016/03/26 23:36:47 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c
SRC +=	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC +=	ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c
SRC +=	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c
SRC +=	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c
SRC +=	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c
SRC +=	ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c
SRC +=	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c
SRC +=	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c
SRC +=	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c
SRC +=	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c
SRC +=	ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c
SRC +=	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c
SRC +=	ft_toupper.c ft_realloc.c ft_isnbr.c ft_lstnew.c
SRC +=	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c
SRC +=	ft_lstmap.c ft_ftoa.c ft_intlen.c ft_isblank.c
SRC +=	ft_atod.c

OBJ = $(SRC:.c=.o)

DEL = rm -f

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(SRC) -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|   was summoned  |"
	@echo "[=================]"

clean:
	@$(DEL) $(OBJ)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean: clean
	@$(DEL) $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

re: fclean all
