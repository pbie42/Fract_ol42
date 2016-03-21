# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/03/21 16:01:58 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra -I includes

SRC = srcs/main.c \
	  srcs/mandelbrot.c \
	  srcs/mandelbralt.c \
	  srcs/julia.c \
	  srcs/burningship.c \
	  srcs/ft_put_pixel.c \
	  srcs/keybinding.c \
	  srcs/zoom.c \
	  srcs/settings.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libft.h -lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
