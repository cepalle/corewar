/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 11:34:40 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 11:34:41 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/corewar.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

static int 	ft_and(t_player *player, int param_1, int param_2)
{
	return (param_1 & param_2);
}

static int 	ft_or(t_player player, int param_1, int param_2)
{
	return (param_1 | param_2);
}

static int 	ft_xor(t_player player, int param_1, int param_2)
{
	return (param_1 ^ param_2);
}

static void ft_st(t_player *player, int nbr, int num_reg, t_vm *vm)
{
	int addr;
	//attention num_reg - 1 ?
	//addr = vm->tab[player.PC->PC] + (nbr % IDX_MOD);
	// SI registre 2 eme parametre juste stock, si indirect on copie a l addresse
	//addr = vm->tab[player->process->PC] + (nbr % IDX_MOD);
	addr = 11 + (nbr % IDX_MOD);
	ft_memcpy(vm->tab + addr, player->process->reg + num_reg, REG_CONTENT_SIZE);
}

void	ft_test_ppichier(t_vm *vm)
{
	int a = 2;

	vm->player[0].process = ft_memalloc(sizeof(t_proc));
	vm->player[0].process->reg[0] = ft_and(&vm->player[0],12, 4);
	ft_printf("le res = %d ", vm->player[0].process->reg[a]);
	ft_st(&vm->player[0], 200, 0, vm);
	ft_print_vm(vm);
	ft_vm_run(vm, 0);

}

//TODO MALLOC DE STRUCT PC POUR TEST