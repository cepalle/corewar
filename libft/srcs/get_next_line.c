/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:44:40 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 18:16:55 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char	*str_realloc(char *str, size_t nwsz)
{
	char	*tmp;

	tmp = str;
	if (!(str = ft_strnew(nwsz)))
	{
		free(tmp);
		return (NULL);
	}
	ft_memmove(str, tmp, ft_strlen(tmp));
	free(tmp);
	return (str);
}

static char	get_char_line_fd(int fd, char *er)
{
	static char		buff[BUFF_SIZE + 1] = { 0 };
	static size_t	i = 0;

	if (buff[i])
		return (buff[i++]);
	ft_bzero(buff, BUFF_SIZE + 1);
	i = 0;
	if (read(fd, buff, BUFF_SIZE) == -1)
	{
		*er = 1;
		return (0);
	}
	return (buff[i++]);
}

static char	feed_str_line_fd(int fd, char **line, char *er, size_t line_size)
{
	char	c;
	size_t	i;

	i = 0;
	while ((c = get_char_line_fd(fd, er)) && c != '\n')
	{
		if (i >= line_size)
		{
			if (!(*line = str_realloc(*line, line_size * 2)))
				return ((*er = 1) - 1);
			line_size *= 2;
		}
		(*line)[i++] = c;
	}
	return (!i && !c);
}

int			get_next_line(const int fd, char **line)
{
	char	er;
	char	eof;

	er = 0;
	if (fd < 0 || !line)
		return (-1);
	if (!(*line = ft_strnew(STR_SIZE)))
		return (-1);
	eof = feed_str_line_fd(fd, line, &er, STR_SIZE);
	if (er || eof)
	{
		free(*line);
		*line = NULL;
	}
	if (er)
		return (-1);
	if (eof)
		return (0);
	return (1);
}
