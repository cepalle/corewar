#include <corewar.h>

void proc_exec(t_vm *vm, t_proc *proc)
{
	t_cmd cmd;
	if (!proc->cmd_save.cmd &&
		!ft_stock_cmd(vm, proc))
	{
		proc->PC++;
		proc->PC %= MEM_SIZE;
		return ;
	}
	proc->cmd_save.cycle_wating--;
	if (proc->cmd_save.cycle_wating <= 0)
	{
		cmd = (t_cmd)proc->cmd_save.cmd;
		cmd(vm, proc);
	}
}

void vm_cycle(t_vm *vm)
{
	unsigned int		i;

	i = 0;
	while (i < vm->nb_process)
	{
		proc_exec(vm, vm->process + i);
		i++;
	}
}
