#include "../includes/asm.h"





t_token get_token(int *i_token, const char *line)
{
	t_token token;






	while (line[*i_token] == '\t' || line[*i_token] == ' ')
		(*i_token)++;
	return token;
}

void line_to_token(t_token *ltken, char *line)
{
	int i_tken;
	int i_line;

	i_tken = 0;
	i_line = 0;

	while (line[i_tken] == '\t' || line[i_tken] == ' ') // skip empty line
		i_tken++;

	while (line[i_line] && !ltken[0].er)
	{
		ltken[i_tken] = get_token(&i_line, line + i_line);
		if (ltken[i_tken].er)
			ltken[0].er = 1;
		i_tken++;
	}
	ltken[i_tken].enum_token = TOKEN_EOL;
};
