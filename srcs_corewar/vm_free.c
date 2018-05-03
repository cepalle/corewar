#include "corewar.h"
#include "libft.h"

void	vm_free(t_vm *vm)
{
	ft_memdel((void **)&(vm->process));
}