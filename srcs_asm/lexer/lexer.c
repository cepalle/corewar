#include "asm.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>


void feed_lexer_files(t_lexer *lexer_res, int fd)
{
	int len_files;
	int i;
	char *line;
	int res;

	i = 0;
	len_files = LEN_INIT_FILES;
	lexer_res->files = ft_memalloc(sizeof(char *) * len_files);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (i + 1 >= len_files)
		{
			lexer_res->files = ft_realloc(lexer_res->files,
			                              len_files * sizeof(char *),
			                              len_files * 2 * sizeof(char *));
			len_files *= 2;
		}
		lexer_res->files[i] = line;
		i++;
	}
	if (res < 0)
	{
		ft_printf("Error with gnl\n");
		lexer_res->er = 1;
	}
}

t_lexer lexer(t_cmdl cmdl)
{
	t_lexer lexer_res;
	t_token ltken[LEN_LTOKEN];
	int i;

	ft_bzero(&lexer_res, sizeof(t_lexer));
	ft_bzero(ltken, sizeof(t_token) * LEN_LTOKEN);
	i = 0;
	feed_lexer_files(&lexer_res, cmdl.fd);
	if (lexer_res.er)
		return lexer_res;
	while (lexer_res.files[i])
	{
		line_to_token(ltken, lexer_res.files, &i);
		if (ltken[0].er)
		{
			//free
			lexer_res.er = 1;
			return lexer_res;
		}
		tab_token_multi_add(&(lexer_res.tab_token), ltken);
		i++;
	}
	//ft_printf("\n### LEXER\n\n");
	//print_tab_token(lexer_res.tab_token);

	if (lexer_res.tab_token.i < 0)
	{
		// free();
		ft_printf("tab token is empty\n");
		lexer_res.er = 1;
	}
	return lexer_res;
};
