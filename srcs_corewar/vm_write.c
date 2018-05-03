
#include "corewar.h"

void	vm_write_1(t_vm *vm, int PC, unsigned char data)
{
	vm->tab[PC % MEM_SIZE] = data;
}

void	vm_write_2(t_vm *vm,  int PC, unsigned short data)
{
	int a;

	a = 0;
	swap_2(data);
	while (a < 2)
	{
		tab[(PC + a) % MEM_SIZE] = (char)data[a];
		a++;
	}
}

void	vm_write_4(t_vm *vm, int PC, unsigned char data)
{
	int a;

	a = 0;
	swap_4(data);
	while (a < 4)
	{
		tab[(PC + a) % MEM_SIZE] = (char)data[a];
		a++;
	}
}


