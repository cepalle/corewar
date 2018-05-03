#include <corewar.h>

// TODO carry
int		cmd_zjmp(t_vm *vm, t_proc *proc)
{
	int		er;
	int		p1;

	er = 0;
	(void)vm;
	p1 = get_param(proc, 0, &er);
	if (er)
		return (0);
	proc->PC += p1; // IDX_MOD ?
	proc->PC %= MEM_SIZE;
	return (1);
}
