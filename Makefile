# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhomche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 23:15:28 by akhomche          #+#    #+#              #
#    Updated: 2023/06/28 23:15:34 by akhomche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC =	srcs/main.c srcs/map.c \
		srcs/read.c \
		srcs/num_rows.c \
		srcs/errors.c \
		srcs/find_biggest_square.c \
		srcs/lib_function.c \
		srcs/lib_function2.c \
		srcs/convert_to_matrix.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
