# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlunga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 08:21:26 by nlunga            #+#    #+#              #
#    Updated: 2019/09/16 11:50:51 by nlunga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a

HEADERS = ft_ls.h

FLAGS = -g -Wall -Werror -Wextra -c

SRCS = ./ft_currentdir.c ./ft_aflag.c ./time.c ./tools.c \
	   ./ft_verflag.c ./ft_isdir.c ./ft_otherdir.c ./ft_check_multi.c\
	   ./ft_check_flags.c ./ft_lflag.c ./ft_out_of_scope.c \
	   ./ft_get_time.c ./ft_getgid.c ./ft_aotherdir.c ./ft_getuid.c\
	   ./da_perm.c ./ft_bubblesort.c ./ft_crflag.c ./ft_rflag.c \
	   
	   #./ft_crflag.c ./ft_conflags.c ./ft_reconflags.c \ 
	   #./get_owner.c ./ft_sort.c ./ft_tflag.c\
	   #./ft_permissions.c ./ft_flags.c \
	   #./ft_permissions.c ./ft_a_otherdir.c ./ft_a_currentdir.c ./ft_aflag.c\ 

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

lin:
	gcc -o ft_ls ft_ls.c ft_ls.a ./libft/libft.a

nnil: all lin clean

no:
	rm ft_ls.a

.PHONY: re, fclean, clean, all
