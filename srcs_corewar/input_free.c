#include "corewar.h"
#include "libft.h"

void	input_free(t_input *input)
{
	ft_memdel((void **)&(input->prog));
}