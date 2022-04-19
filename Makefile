NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
XSYSCALL_SRCS = $(addprefix srcs/xsyscall/, \
		xclose.c xfork.c xopen.c xpipe.c xwaitpid.c xdup2.c \
		)
XLIBFT_SRCS = $(addprefix srcs/xlibft/, \
		ft_xcalloc.c ft_xlstnew.c ft_xsplit.c ft_xstrdup.c ft_xstrjoin.c \
		)
ENV_SRCS = $(addprefix srcs/env/, \
		env.c get_env.c get_envlist.c get_envp.c remove_env.c set_env.c \
		)
BUILTIN_SRCS = $(addprefix srcs/builtin/, \
		cd.c echo.c env.c exit.c export.c pwd.c unset.c \
		)
EXECUTER_SRCS = $(addprefix srcs/executer/, \
		builtin.c executer.c fd_getter.c get_fullpath.c heredoc.c\
		)
EXPANSION_SRCS = $(addprefix srcs/expansion/, \
		expansion.c \
		)
LEXER_SRCS = $(addprefix srcs/lexer/, \
		initialize_lexer.c lexer_utils.c lexer.c\
		)
PARSER_SRCS = $(addprefix srcs/parser/, \
		parser.c \
		)
UTILS_SRCS = $(addprefix srcs/utils/, \
		error.c util.c \
		)
SRCS = main.c $(XSYSCALL_SRCS) $(XLIBFT_SRCS) $(BUILTIN_SRCS) $(ENV_SRCS) $(EXECUTER_SRCS) $(EXPANSION_SRCS) $(LEXER_SRCS) $(PARSER_SRCS) $(UTILS_SRCS)
OBJS = $(SRCS:%.c=%.o)
LIBS = -lft -Llibft -lreadline -L$(shell brew --prefix readline)/lib
INCS = -Ilibft/includes -Iincludes -I$(shell brew --prefix readline)/include
LIBFT = libft/libft.a

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

all: $(NAME)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME) $(NAME_BONUS)

clean:
	make clean -C libft
	$(RM) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all fclean clean re

.PHONY: test
test: ultest itest

.PHONY: ltest
ltest: ultest iltest

.PHONY: utest
utest:
	make -C tests/google_tests

.PHONY: ultest
ultest:
	make -C tests/google_tests ltest

.PHONY: itest
itest: $(NAME)
	bash ./tests/shell_scripts/main.sh

.PHONY: val_build
val_build:
	docker build -t minishell_valgrind .

.PHONY: val
val:
	docker run -it --rm -v $(PWD):/app minishell_valgrind
