# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:54:15 by acolas            #+#    #+#              #
#    Updated: 2019/01/07 17:26:04 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = acolas.filler
SRC = main.c \
	  src/ft_set_player.c\

CC = gcc
HEADER = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
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
