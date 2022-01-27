#include "xsyscall.h"

int	xpipe(int fildes[2])
{
	int	status;

	status = pipe(fildes);
	if (status == -1)
	{
		perror("pipe");
		exit(1);
	}
	return (status);
}
