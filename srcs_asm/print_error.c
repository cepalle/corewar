#include "../libft/includes/libft.h"

int asm_usage(void)
{
	ft_printf("Usage: ./bin_ref/asm [-a] <sourcefile.s>\n");
	ft_printf("    -a : Display AST\n");
	return (-1);
};

int print_local_error(char **files, const int *col, const int *line, char *msg)
{
	int i;

	i = 0;
	if (msg)
		ft_printf("%s\n", msg);
	if (files && line)
		ft_printf("%s\n", files[*line]);
	if (files && line && col)
	{
		while (i + 1 < *col)
		{
			ft_printf(" ");
			i++;
		}
		ft_printf("\033[31m^\033[0m\n"); // COLOR ?
	}
	if (line && col)
		ft_printf("line: %d column: %d\n", *line + 1, *col + 1);
	else if (line)
		ft_printf("line: %d\n", *line + 1);
	return (-1);
};
