

#include "../includes/corewar.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"


void 	ft_live(t_player *player, int Num_player)
{
	player->live = player->live + 1;
	player->last_live = player->last_live + 1;
}

int 	ft_ld(t_player player, int nbr)
{
//	% 4294967295
//	pas de message d'erreur en cas de depassement
	return (nbr % IDX_MOD);
}

void 	ft_st(t_player player, int nbr, int num_reg, t_vm *vm)
{
	int addr;

	addr = vm->tab[player.process->PC] + (nbr % IDX_MOD);
	ft_memcpy(vm->tab + addr, player.process->reg + num_reg, REG_CONTENT_SIZE);
}

int 	ft_add(t_player player ,int num_reg1,int num_reg2)
{
//	% 4294967295
//	pas de message d'erreur en cas de depassement
	return (player.process->reg[num_reg1] + player.process->reg[num_reg2]);
}

int 	ft_sub(t_player player ,int num_reg1,int num_reg2)
{
//	penser a modifier carry si erreur ou pas
//	erreur potentiel : depassement int max
	return (player.process->reg[num_reg1] - player.process->reg[num_reg2]);
}

int 	ft_and(t_player *player, int param_1, int param_2)
{
	return (param_1 & param_2);
}

int 	ft_or(t_player *player, int param_1, int param_2)
{
	return (param_1 | param_2);
}

int 	ft_xor(t_player *player, int param_1, int param_2)
{
	return (param_1 ^ param_2);
}

int 	ft_ldi(int param_1, int param_2, t_vm *vm)
{
//	mettre % 512 ?
	return (vm->tab[param_1 + param_2]);
}

int		ft_sti(int reg, int param_1, int param_2 , t_vm *vm)
{
	int addr;

	addr = param_1 + param_2;
	ft_memcpy(vm->tab + addr, &reg, REG_CONTENT_SIZE);
}


int 	ft_lld(t_player player, int nbr)
{
//	ajouter % 4096? ou autre limite
	return (nbr);
}

int 	ft_lldi(int param_1, int param_2, t_vm *vm)
{
//	ldi sans modulo
	return (vm->tab[param_1 + param_2]);
}

void 	ft_aff(int index, t_vm *vm)
{
	ft_putchar(vm->tab[index]);
}


void	ft_lfork(t_vm *vm, int num_player, int num_process)
{
	return;
}

void	ft_fork(t_vm *vm, int num_player, int num_process)
{
	return;
}

void 	ft_zjmp(t_player *player, int num_player, int num_proc, int index)
{
	player[num_player].process[num_proc].process = index;
}
