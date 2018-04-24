#include "libft.h"
#include <unistd.h>

size_t write_mem(int fd, void *pt, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		write(fd, pt + size - 1 - i, 1);
		i++;
	}
	return size;
}
