# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:54:15 by acolas            #+#    #+#              #
#    Updated: 2019/01/13 16:52:19 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC_FILE = acolas.filler
SRCS = main.c \
	  src/ft_player.c\
	  src/error.c\
	  src/ft_parsing.c\
	  src/ft_algo.c

OBJS = $(SRCS:.c=.o)
CC = gcc
INCLUDES = -I libft/ -I ./includes
CFLAGS = -Wall -Wextra -Werror -g#-fsanitize=address -g

.PHONY : all clean fclean re

all : $(EXEC_FILE)

$(EXEC_FILE) : $(OBJS) libft/libft.a  
		@$(CC) -Llibft -lft $^ -o $@

%.o: %.c
	    @$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

libft/libft.a:
		@make -C libft

clean :
		@make -C libft clean
		@rm -rf $(OBJS)

fclean : clean
		@make -C libft fclean
		@rm -rf $(EXEC_FILE)

re : fclean all
