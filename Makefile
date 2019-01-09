# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:54:15 by acolas            #+#    #+#              #
#    Updated: 2019/01/09 15:57:58 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = acolas.filler
SRC = main.c \
	  src/ft_player.c\
	  src/error.c\
	  src/ft_parsing.c\


CC = gcc
HEADER = ./libft/libft.a -I ./includes
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
		@make -C libft
		@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(HEADER)

clean :
		@make -C libft clean
		@/bin/rm -rf $(OBJ)

fclean : clean
		@make -C libft fclean
		@/bin/rm -rf $(NAME)

re : fclean all
