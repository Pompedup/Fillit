# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 14:41:16 by abezanni          #+#    #+#              #
#    Updated: 2017/11/28 15:17:24 by abezanni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c ft_create_maill.c resolve.c

FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIB = -L ./libft/ -lft

all : mlib $(NAME)

mlib :
	make -C ./libft/

$(NAME) : $(OBJ)
	gcc $(FLAG) -o $@ $^ $(LIB)

%.o : %.c
	gcc $(FLAG) -c $< -I.

clean :
	make clean -C ./libft/
	/bin/rm -f $(OBJ)

fclean : clean
	make fclean -C ./libft/
	/bin/rm -f $(NAME)

re : fclean	all
