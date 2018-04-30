/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/29 17:07:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 17:07:38 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"

static	int		ft_check_player(char *argv)
{
	int		fd;
	size_t	len;

	ft_printf("ft_check_player\n");
	len = ft_strlen(argv);
	if (len > 4 && ((ft_strncmp(argv + (len - 4), ".cor", 4) != 0)))
	{
		ft_printf("%s n'est pas un champion\n", argv);
		return (0);
	}
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("fichier inexistant\n");
		return (0);
	}
	close(fd);
	ft_printf("%s est bien un champion\n", argv);
	return (1);
}

static	int		ft_check_option(char *argv)
{
	ft_printf("ft_check_option\n");
//	TODO: penser a choisir les options que l'on va mettre en place
	if (ft_strcmp(argv, "-n") == 0)
	{
		ft_printf("Ncurses output mode\n");
		return (1);
	}
	if (ft_strcmp(argv, "-a") == 0)
	{
		ft_printf("Prints output from \"aff\" (Default is to hide it)\n");
		return (1);
	}
	if (ft_strcmp(argv, "-b") == 0)
	{
		ft_printf("Binary output mode for corewar.42.fr\n");
		return (1);
	}
	ft_printf("option non reconnue\n");
	return (0);
}

void			ft_usage(void)
{
	ft_printf("ft_usage\n");
	ft_printf(
	"Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] "
			"<champion1.cor> <...>\n"
	"    -a       : Prints output from \"aff\" (Default is to hide it)\n"
	"#### TEXT OUTPUT MODE ##################################################\n"
	"    -d N     : Dumps memory after N cycles then exits\n"
	"    -s N     : Runs N cycles, dumps memory, pauses, then repeats\n"
	"    -v N     : Verbosity levels, can be added together to enable several\n"
	"                - 0 : Show only essentials\n"
	"                - 1 : Show lives\n"
	"                - 2 : Show cycles\n"
	"                - 4 : Show operations (Params are NOT litteral ...)\n"
	"                - 8 : Show deaths\n"
	"                - 16 : Show PC movements (Except for jumps)\n"
	"#### BINARY OUTPUT MODE ################################################\n"
	"    -b       : Binary output mode for corewar.42.fr\n"
	"    --stealth: Hides the real contents of the memory\n"
	"#### NCURSES OUTPUT MODE ###############################################\n"
	"    -n       : Ncurses output mode\n"
	"    --stealth: Hides the real contents of the memory\n"
	"########################################################################");
}

static	int		ft_check_arg(char **argv)
{
	int a;

	ft_printf("ft_check_arg\n");
	a = 1;
	while (argv[a])
	{
		if (ft_check_option(argv[a]) == 0 && ft_check_player(argv[a]) == 0)
		{
			ft_printf("Can't read source file %s\n", argv[a]);
			return (0);
		}
		a++;
	}
	return (1);
}

int				ft_check_error(int argc, char **argv)
{
	ft_printf("ft_check_error\n");
	if (argc == 1 || ft_count_player(argv) == 0)
	{
		ft_usage();
		return (0);
	}
	if (ft_check_arg(argv) == 0)
		return (0);
	return (1);
}
//TODO: penser a gerer limite de 4 joueurs max et quelles options gerer
