/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 12:45:31 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 12:53:28 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>

static t_cmdl	check_erro_cmdl(int argc, char **argv, t_cmdl *cmdl)
{
	size_t	len;

	if (argc != 1)
	{
		asm_usage();
		cmdl->er = 1;
		return (*cmdl);
	}
	len = ft_strlen(argv[0]);
	if (len < 3 ||
		argv[0][len - 1] != 's' ||
		argv[0][len - 2] != '.')
	{
		ft_printf("file name must finish with .s and not be empty\n");
		cmdl->er = 1;
		return (*cmdl);
	}
	return (*cmdl);
}

t_cmdl			cmd_input(int argc, char **argv)
{
	t_cmdl	cmdl;

	ft_bzero(&cmdl, sizeof(t_cmdl));
	check_erro_cmdl(argc, argv, &cmdl);
	if (cmdl.er)
		return (cmdl);
	cmdl.fd = open(argv[0], O_RDONLY);
	if (cmdl.fd < 0)
	{
		ft_printf("No file name %s\n", argv[0]);
		cmdl.er = 1;
	}
	cmdl.file_name = argv[0];
	return (cmdl);
}
