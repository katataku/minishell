NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
XSYSCALL_SRCS = $(addprefix srcs/xsyscall/, \
		xclose.c xfork.c xopen.c xpipe.c xwaitpid.c xdup2.c \
		)
SRCS = main.c $(XSYSCALL_SRCS) 
OBJS = $(SRCS:%.c=%.o)
LIBS = -lft -Llibft
INCS = -Ilibft/includes -Iincludes

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

test:
	make -C tests/google_tests

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all fclean clean re test
