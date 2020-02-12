# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlunga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 13:45:30 by nlunga            #+#    #+#              #
#    Updated: 2019/09/30 09:23:01 by nlunga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

FLAGS = -Wall -Werror -Wextra -c

SRCS =  ./ft_memset.c ./ft_itoa.c ./ft_bzero.c ./ft_memcpy.c\
	  ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c\
	  ./ft_strlen.c ./ft_strdup.c ./ft_strcpy.c ./ft_words.c\
	  ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c ./ft_strrev.c\
	  ./ft_strlcat.c ./ft_strchr.c ./ft_strstr.c ./ft_swap.c\
	  ./ft_strrchr.c ./ft_strnstr.c ./ft_strcmp.c ./ft_strcspn.c\
	  ./ft_strncmp.c ./ft_atoi.c ./ft_isalpha.c ./ft_putnbr_add.c\
	  ./ft_isdigit.c ./ft_isascii.c ./ft_isalnum.c ./ft_putstr_add.c\
	  ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c\
	  ./ft_putchar.c ./ft_putchar_fd.c ./ft_putstr.c\
	  ./ft_putstr_fd.c ./ft_putendl.c ./ft_putendl_fd.c ./ft_strequ.c\
	  ./ft_strnequ.c ./ft_strclr.c  ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c\
	  ./ft_strtrim.c ./ft_strsub.c ./ft_striter.c ./ft_striteri.c\
	  ./ft_strjoin.c ./ft_strsplit.c ./ft_noWhite.c\
	 ./ft_strmap.c ./ft_putnbr_fd.c ./ft_strmapi.c ./ft_putnbr.c\
	  ./ft_memalloc.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c \
	  ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_intlen.c ft_addpath.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): clean
	gcc $(FLAGS) $(SRCS) $(HEADERS)  
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

jt:
	gcc main.c libft.a

.PHONY: re, fclean, clean, all
