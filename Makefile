# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlunga <nlunga@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 08:21:26 by nlunga            #+#    #+#              #
#    Updated: 2020/02/10 14:52:19 by nlunga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a

HEADERS = ./includes/ft_ls.h

FLAGS = -Wall -Werror -Wextra -c

SRCS = ./srcs/ft_bubblesort.c ./srcs/ft_display.c ./srcs/ft_flags.c\
	   ./srcs/ft_opendir.c ./srcs/ft_verflag.c ./srcs/permissions.c\
	   ./srcs/tools.c ./srcs/ft_tflag.c

# OBJS = $(SRCS:.c=.o)
OBJS = ./ft_bubblesort.o ./ft_display.o ./ft_flags.o\
	   ./ft_opendir.o ./ft_verflag.o ./permissions.o\
	   ./tools.o ./ft_tflag.o

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

lin:
	gcc -o ft_ls ./srcs/ft_ls.c ft_ls.a ./libft/libft.a

nnil: all lin clean

no:
	rm ft_ls.a

.PHONY: re, fclean, clean, all
