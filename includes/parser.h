#ifndef PARSER_H
# define PARSER_H

# include "define.h"
# include "xlibft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void		free_exec_info(t_exec_info *exec_info);
t_exec_info	*parser(t_token *token);

#endif
