#include "xsyscall.h"

int	xopen(const char *path, int oflag, int mode)
{
	int	fd;

	fd = open(path, oflag, mode);
	if (fd < 0)
	{
		perror(path);
		exit(1);
	}
	return (fd);
}
