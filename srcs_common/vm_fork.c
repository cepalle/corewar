#include <corewar.h>
#include "libft.h"

void	vm_fork(t_vm *vm, t_proc *proc, int add)
{
	t_proc to_add;

	to_add = *proc;
	to_add.PC += add;
	to_add.PC %= MEM_SIZE;
	if (vm->nb_process >= vm->len_process)
	{
		vm->process = ft_realloc(vm->process,
			sizeof(t_proc) * vm->len_process,
			sizeof(t_proc) * vm->len_process * 2);
		vm->len_process *= 2;
	}
	vm->process[vm->nb_process] = to_add;
	vm->nb_process++;
}