#include <corewar.h>

// TODO carry
int		cmd_zjmp(t_vm *vm, int ipr)
{
	int		er;
	int		p1;

	er = 0;
	(void)vm;
	p1 = get_param(vm->process + ipr, 0, &er);
	if (er)
		return (0);
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC, p1);
	return (1);
}
