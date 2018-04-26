#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

int open_new_file(char *file_name)
{
	int fd;
	size_t len;
	char *new_file_name;

	len = ft_strlen(file_name);
	new_file_name = ft_strnew(len + 3);
	ft_strcpy(new_file_name, file_name);
	new_file_name[len + 1] = 'r';
	new_file_name[len] = 'o';
	new_file_name[len - 1] = 'c';

	fd = open(new_file_name, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	//ft_printf("new_file_name: '%s' fd: %d\n", new_file_name, fd);
	if (fd > 0)
	{
		//ft_printf("result write in %s\n", new_file_name);
		//write(fd, "test\n", 5);
	}
	return fd;
};
