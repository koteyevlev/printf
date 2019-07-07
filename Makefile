# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 12:33:09 by lbritni           #+#    #+#              #
#    Updated: 2019/07/07 22:15:48 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OUT = *.o libft/*.o
SRC1 = *.c libft/*.c
HEADERS = printf.h libft/libft.h

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror -std=c99 $(SRC1) $(HEADERS) 
	@ar rc $(NAME) *.o;
	@ranlib $(NAME);

clean:
	@/bin/rm -f $(OUT)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *h.gch
	@/bin/rm -f libft/libft.a
	@/bin/rm -f libft/*h.gch

re: fclean all

comp: all clean
	@gcc -Wall -Wextra -Werror -o check main.c -L ./ -lftprintf
