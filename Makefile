# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 12:33:09 by lbritni           #+#    #+#              #
#    Updated: 2019/07/07 18:52:41 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

OUT = *.o
SRC = *.c libft/*.c

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC)

clean:
		/bin/rm -f $(OUT)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
