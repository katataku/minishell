#include "xsyscall.h"

pid_t	xwaitpid(pid_t pid, int *stat_loc, int options)
{
	pid_t	ret;

	ret = waitpid(pid, stat_loc, options);
	if (ret == -1)
	{
		perror("waitpid");
		exit(1);
	}
	return (ret);
}
