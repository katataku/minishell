#include "xsyscall.h"

int	xclose(int fildes)
{
	int	status;

	status = close(fildes);
	if (status == -1)
	{
		perror("close");
		exit(1);
	}
	return (status);
}
