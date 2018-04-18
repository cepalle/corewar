#include "../libft/includes/libft.h"

int put_error(char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	return (-1);
}

int asm_usage(void)
{
	put_error("Usage: ./bin_ref/asm [-a] <sourcefile.s>\n");
	put_error("    -a : Display AST\n");
	return (-1);
};
