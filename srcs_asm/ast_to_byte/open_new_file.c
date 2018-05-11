/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_new_file.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 13:20:32 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 13:20:39 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		open_new_file(char *file_name)
{
	int		fd;
	size_t	len;
	char	*new_file_name;

	len = ft_strlen(file_name);
	new_file_name = ft_strnew(len + 3);
	ft_strcpy(new_file_name, file_name);
	new_file_name[len + 1] = 'r';
	new_file_name[len] = 'o';
	new_file_name[len - 1] = 'c';
	fd = open(new_file_name, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
		ft_printf("result will write in %s\n", new_file_name);
	else
		ft_printf("Unexpected error, can't write the file.cor\n");
	free(new_file_name);
	return (fd);
}
