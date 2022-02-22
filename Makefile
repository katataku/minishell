NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
XSYSCALL_SRCS = $(addprefix srcs/xsyscall/, \
		xclose.c xfork.c xopen.c xpipe.c xwaitpid.c xdup2.c \
		)
XLIBFT_SRCS = $(addprefix srcs/xlibft/, \
		ft_xcalloc.c ft_xsplit.c ft_xstrdup.c ft_xstrjoin.c \
		)
EXECUTER_SRCS = $(addprefix srcs/executer/, \
		executer.c \
		)
LEXER_SRCS = $(addprefix srcs/lexer/, \
		initialize_lexer.c lexer_utils.c lexer.c\
		)
PARSER_SRCS = $(addprefix srcs/parser/, \
		parser.c \
		)
SRCS = main.c $(XSYSCALL_SRCS) $(XLIBFT_SRCS) $(EXECUTER_SRCS) $(LEXER_SRCS) $(PARSER_SRCS)
OBJS = $(SRCS:%.c=%.o)
LIBS = -lft -Llibft -lreadline -L$(shell brew --prefix readline)/lib
INCS = -Ilibft/includes -Iincludes -I$(shell brew --prefix readline)/include

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

test:
	make -C tests/google_tests

ltest:
	make -C tests/google_tests ltest

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all fclean clean re test ltest
