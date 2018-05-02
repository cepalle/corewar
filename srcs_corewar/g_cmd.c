#include "corewar.h"

static t_cmd	g_cmd_tab[17] =
{
	&ft_ld,
	&ft_live,
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
