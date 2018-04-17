#include "../includes/asm.h"
#include <fcntl.h>

t_cmdl cmd_input(int argc, char **argv)
{
	t_cmdl cmdl;
	int fd;

	cmdl = {0, 0, 0};
	if (argc != 1 && argc != 0)
	{
		asm_usage();
		cmdl.er = 1;
		return cmdl;
	}
	if (argv == 1)
	{
		if (!ft_strequ("-a", argv[0]))
		{
			asm_usage();
			cmdl.er = 1;
			return cmdl;
		}
		cmdl.opt_a = 1;
	}
	fd = open(argv[0 + cmdl.opt_a], O_RDONLY);
	if (fd < 0)
	{
		// perror
		cmdl.er = 1;
	}
	return cmdl;
};