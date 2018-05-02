#include "corewar.h"
#include "../libft/includes/libft.h"

static t_cmd	g_cmd_tab[17] =
{
	&ft_live,
	&ft_ld,
	&ft_st,
	&ft_add,
	&ft_sub,
	&ft_and,
	&ft_or,
	&ft_xor,
	&ft_ldi,
	&ft_sti,
	&ft_lld,
	&ft_lldi,
	&ft_aff,
	&ft_lfork,
	&ft_fork,
	&ft_zjmp,
	NULL,
};


t_op		*gcmdpt(void)
{
	return (g_op_tab);
}

t_op		get_cmd(char *cmd)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (ft_strequ(gopt()[i].name, cmd))
			return (gopt()[i]);
		i++;
	}
	ft_printf("get_op_name cmd no found\n");
	return (gopt()[OP_TAB_LENGTH]);
}
