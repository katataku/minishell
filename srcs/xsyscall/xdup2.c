#include "xsyscall.h"

int	xdup2(int fildes, int fildes2)
{
	int	status;

	status = dup2(fildes, fildes2);
	if (status == -1)
	{
		perror("dup2");
		exit(1);
	}
	return (status);
}
