# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acolas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 14:35:06 by acolas            #+#    #+#              #
#    Updated: 2017/11/29 14:54:38 by acolas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ME = acolas.filler
SRC_DIR = ./src
SRC = main.c \	
									

CC = gcc
OBJ = $(SRC:%.c=%.o)
	CFLAGS = -Wall -Werror -Wextra
	RM = rm -f
	DIR_LIB	= libft
	LIBFT	= $(DIR_LIB)/libft.a

all : $(NAME)

$(NAME): $(LIBFT)
		@$(CC) $(CFLAGS) -c $(addprefix $(SRC_DIR)/,$(SRC))
		@ar -rc $(NAME) $(OBJ) ./libft/*.o

$(LIBFT):
		@make -C $(DIR_LIB)

clean:
		@make clean -C $(DIR_LIB)
		@$(RM) $(OBJ)

fclean: clean
		@make fclean -C $(DIR_LIB) 
		@$(RM) $(NAME) $(HEADER)

re: fclean all

.PHONY : clean fclean re all
