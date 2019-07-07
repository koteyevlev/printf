# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 15:11:11 by wtorwold          #+#    #+#              #
#    Updated: 2019/07/03 16:15:02 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OUT = ft_*.o
SRC = ft_itoa.c ft_strindex.c ft_memset.c ft_strdel.c ft_strnew.c ft_lstadd.c ft_putchar.c ft_strdup.c ft_strnstr.c ft_lstdel.c ft_putchar_fd.c ft_strequ.c ft_strrchr.c ft_arrmem.c ft_lstdelone.c ft_putendl.c ft_striter.c ft_strsplit.c ft_arrsplit.c ft_lstiter.c ft_putendl_fd.c ft_striteri.c ft_strstr.c ft_atoi.c ft_lstmap.c ft_putnbr.c ft_strjoin.c ft_strsub.c ft_bzero.c ft_lstnew.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_countdigit.c ft_memalloc.c ft_putstr.c ft_strlen.c ft_tolower.c ft_countword.c ft_memccpy.c ft_putstr_fd.c ft_strmap.c ft_toupper.c ft_isalnum.c ft_memchr.c ft_strcat.c ft_strmapi.c ft_isalpha.c ft_memcmp.c ft_strchr.c ft_strncat.c ft_isascii.c ft_memcpy.c ft_strclr.c ft_strncmp.c ft_isdigit.c ft_memdel.c ft_strcmp.c ft_strncpy.c ft_isprint.c ft_memmove.c ft_strcpy.c ft_strnequ.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
