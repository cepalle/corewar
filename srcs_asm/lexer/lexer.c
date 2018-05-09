/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:57 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:59 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void			feed_lexer_files(t_lexer *lexer_res, int fd)
{
	int		len_files;
	int		i;
	char	*line;
	int		res;

	i = 0;
	len_files = LEN_INIT_FILES;
	lexer_res->file = ft_memalloc(sizeof(char *) * len_files);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (i + 1 >= len_files)
		{
			lexer_res->file = ft_realloc(lexer_res->file,
			len_files * sizeof(char *),
			len_files * 2 * sizeof(char *));
			len_files *= 2;
		}
		lexer_res->file[i] = line;
		i++;
	}
	if (res < 0)
	{
		ft_printf("Unexpected error with gnl\n");
		lexer_res->er = 1;
	}
}

static t_lexer	free_error(t_lexer *lexer_res)
{
	free_lexer(*lexer_res);
	lexer_res->er = 1;
	return (*lexer_res);
}

static t_lexer	free_print(t_lexer *lexer_res)
{
	ft_printf("lexer: the program is empty\n");
	return (free_error(lexer_res));
}

t_lexer			lexer(t_cmdl cmdl)
{
	t_lexer		lexer_res;
	t_token		ltken[LEN_LTOKEN];
	int			i_line;

	ft_bzero(&lexer_res, sizeof(t_lexer));
	lexer_res.tab_token.i = -1;
	i_line = 0;
	feed_lexer_files(&lexer_res, cmdl.fd);
	if (lexer_res.er)
		return (free_error(&lexer_res));
	while (lexer_res.file[i_line])
	{
		ft_bzero(ltken, sizeof(t_token) * LEN_LTOKEN);
		line_to_token(ltken, lexer_res.file, &i_line);
		tab_token_multi_add(&(lexer_res.tab_token), ltken);
		if (ltken[0].er)
			return (free_error(&lexer_res));
		i_line++;
	}
	if (!lexer_res.file[0] || lexer_res.tab_token.i < 0)
		return (free_print(&lexer_res));
	return (lexer_res);
}
