# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:41:16 by glebouch          #+#    #+#              #
#    Updated: 2018/12/18 19:56:49 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit

SRC =	src/fillit.c\
		src/ft_create_maill.c\
		src/resolve.c\
		src/gestion_pos.c\

CFLAGS =	-Wall -Wextra -Werror -I ./inc

OBJ =	$(SRC:.c=.o)

LIB =	-L ./libft/ -lft

CC =	gcc

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft/
	gcc $(FLAG) -o $@ $^ $(LIB)

# %.o : %.c
	# gcc $(FLAG) -c $< -I.

clean :
	make clean -C ./libft/
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re : fclean	all
