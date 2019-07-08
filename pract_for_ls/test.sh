make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o test.o -c test.c
clang -o test_gnl test.o -I libft/includes -L libft/ -lft
