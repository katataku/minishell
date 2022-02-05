NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./includes
SRCS := get_next_line.c
SRCS += $(addprefix ft_ctype/, \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_isspace.c ft_todigit.c ft_tolower.c ft_toupper.c \
		)
SRCS += $(addprefix ft_dlist/, \
		dlst_assign.c dlst_create_node.c dlst_erase.c dlst_pop_back.c dlst_pop_front.c \
		dlst_push_back.c dlst_push_front.c \
		)
SRCS += $(addprefix ft_list/, \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		)
SRCS += $(addprefix ft_stdio/, \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		)
SRCS += $(addprefix ft_stdlib/, \
		ft_abs.c ft_atoi.c ft_atol.c ft_calloc.c ft_itoa.c \
		)
SRCS += $(addprefix ft_string/, \
		ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		)
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all fclean clean re
