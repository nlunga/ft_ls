# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlunga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 08:21:26 by nlunga            #+#    #+#              #
#    Updated: 2019/08/22 16:25:13 by nlunga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a

HEADERS = ft_ls.h

FLAGS = -Wall -Werror -Wextra -c

SRCS = ft_conflags.c ./ft_reconflags.c ./ft_a_currentdir.c ./ft_currentdir.c\
	   ./ft_verflag.c ./ft_flags.c ./ft_isdir.c ./ft_otherdir.c\
	   ./ft_check_flags.c ./ft_lflag.c ./ft_out_of_scope.c ./ft_check_multi.c\
	   ./ft_get_time.c ./ft_aflag.c ./ft_a_otherdir.c ./ft_getgid.c\
	   ./ft_getuid.c ./da_perm.c\
	   #./get_owner.c\
	   #./ft_permissions.c\
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
