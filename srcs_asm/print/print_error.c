#include "libft.h"

int	asm_usage(void)
{
	ft_printf("Usage: ./bin_ref/asm [-a] <sourcefile.s>\n");
	ft_printf("    -a : Display AST\n");
	return (-1);
}

int	print_local_error(char **files,
						 const int *i_col, const int *i_line, char *msg)
{
	int i;

	i = 0;
	if (msg)
		ft_printf("%s\n", msg);
	if (files && i_line)
		ft_printf("%s\n", files[*i_line]);
	if (files && i_line && i_col)
	{
		while (i < *i_col)
		{
			if (files[*i_line][i] == '\t')
				ft_printf("\t");
			else
				ft_printf(" ");
			i++;
		}
		ft_printf("\033[31m^\033[0m\n");
	}
	if (i_line && i_col)
		ft_printf("line: %d column: %d\n", *i_line + 1, *i_col + 1);
	else if (i_line)
		ft_printf("line: %d\n", *i_line + 1);
	return (-1);
}
