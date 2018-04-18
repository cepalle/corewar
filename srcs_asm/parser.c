#include "asm.h"
#include "libft.h"

t_parser parser(void)
{
	t_parser parser_res;

	ft_bzero(&parser_res, sizeof(t_parser));
	return parser_res;
};
