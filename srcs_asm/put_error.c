#include "../libft/includes/libft.h"

int asm_usage(void)
{
	ft_printf("Usage: ./bin_ref/asm [-a] <sourcefile.s>\n");
	ft_printf("    -a : Display AST\n");
	return (-1);
};

int print_local_error(char **files, int *col, int *line, char *msg)
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
		ft_printf("^\n"); // COLOR ?
	}
	if (line && col)
		ft_printf("line: %d column: %d\n", *line, *col);
	else if (line)
		ft_printf("line: %d\n", *line);
	return (-1);
};
