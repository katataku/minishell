#ifndef MINISHELL_H
# define MINISHELL_H
# include "typedefs.h"

# include <stdio.h>
# define READ_INDEX 0
# define WRITE_INDEX 1

# define ERR_CODE_GENERAL 1
# define ERR_CODE_CAN_NOT_EXECUTE 126
# define ERR_CODE_COMMAND_NOT_FOUND 127

t_token	*tokenize(const char *str);

#endif
