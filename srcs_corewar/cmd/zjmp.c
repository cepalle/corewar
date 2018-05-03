#include <corewar.h>

// TODO carry
int		cmd_add(t_vm *vm, t_proc *proc)
{
	int		er;
	int		ri1;
	int		ri2;
	int		ri3;

	er = 0;
	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	ri1 = get_i_reg(proc, 0, &er);
	ri2 = get_i_reg(proc, 1, &er);
	ri3 = get_i_reg(proc, 2, &er);
	if (er)
		return (0);
	proc->reg[ri3] = proc->reg[ri1] + proc->reg[ri2];
	return (1);
}
