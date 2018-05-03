#include "libft.h"
#include "corewar.h"

void	vm_dump_mem(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE / 32)
	{
		j = 0;
		if (i)
			ft_printf("%#.4x: ", i * 32); // test 0 printf
		else
			ft_printf("0x0000: ");
		while (j < 32)
		{
			ft_printf("%.2hhx ", vm->tab[i * 32 + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
