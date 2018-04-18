#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <errno.h>

t_cmdl cmd_input(int argc, char **argv)
{
	t_cmdl cmdl;
	int fd;

	ft_bzero(&cmdl, sizeof(t_cmdl));
	if (argc != 1 && argc != 0)
	{
		asm_usage();
		cmdl.er = 1;
		return cmdl;
	}
	if (argc == 1)
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
		perror(NULL); // TODO change?
		cmdl.er = 1;
	}
	return cmdl;
};
