# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:41:16 by glebouch          #+#    #+#              #
#    Updated: 2017/11/29 12:08:02 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c ft_create_maill.c resolve.c gestion_pos.c

FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIB = -L ./libft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft/
	gcc $(FLAG) -o $@ $^ $(LIB)

%.o : %.c
	gcc $(FLAG) -c $< -I.

clean :
	make clean -C ./libft/
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re : fclean	all
