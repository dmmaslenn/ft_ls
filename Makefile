#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaslenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 17:30:41 by dmaslenn          #+#    #+#              #
#    Updated: 2017/05/31 17:45:47 by dmaslenn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls

SRC =	main.c \
		ft_ls.c \
		folder.c \
		list.c \
		random.c \
		read.c \
		sortit.c \
		stat.c \
		statt.c \
		time.c \
		validateit.c \
		validation.c \
		validationer.c \
		sortfolder.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -Wall -Werror -Wextra

INC = ./

LIB =  -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@$(CC) $(FLG) -I $(INC) -c $<

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@rm -rf $(NAME)

re: fclean all