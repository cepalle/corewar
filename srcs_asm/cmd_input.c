#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <errno.h>

// file name must be name.s ?
t_cmdl cmd_input(int argc, char **argv)
{
    t_cmdl cmdl;

    ft_bzero(&cmdl, sizeof(t_cmdl));
    if ((argc != 2 && argc != 1) ||
        (argc == 2 && !ft_strequ("-a", argv[0])) ||
        (argc == 1 && ft_strequ("-a", argv[0])))
    {
        asm_usage();
        cmdl.er = 1;
        return cmdl;
    }
    cmdl.opt_a = argc == 2;
    cmdl.fd = open(argv[0 + cmdl.opt_a], O_RDONLY);
    if (cmdl.fd < 0)
    {
        ft_printf("No file name %s\n", argv[0 + cmdl.opt_a]);
        cmdl.er = 1;
    }
    return cmdl;
};
