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

static	void	ft_fill_player(char *argv, t_input *input, int fd)
{
	ssize_t	ret;

	ret = read(fd, &input->head[input->nb_p], sizeof(t_header));
	swap_4(&input->head[input->nb_p].magic);
	swap_4(&input->head[input->nb_p].prog_size);
	input->prog[input->nb_p] = ft_memalloc(sizeof(char) *
							input->head[input->nb_p].prog_size);
	ret = read(fd, input->prog[input->nb_p],
			   input->head[input->nb_p].prog_size);
}

static	int		ft_check_player(char *argv, t_input *input)
{
	int		fd;
	size_t	len;

	if (input->nb_p >= 4)
	{
		ft_printf("too many player\n");
		return (0);
	}
	len = ft_strlen(argv);
	if (len > 4 && ((ft_strncmp(argv + (len - 4), ".cor", 4) != 0)))
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unreachable file\n");
		return (0);
	}
	ft_fill_player(argv, input, fd);
	input->nb_p = input->nb_p + 1;
	close(fd);
	return (1);
}

static	int ft_str_is_digit(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (!ft_isdigit(str[a]))
			return (0);
		a++;
	}
	return (1);
}

static	int		ft_check_option(char **argv, t_input *input, int *a, int argc)
{
	if (ft_strcmp(argv[*a], "-d") == 0)
	{
		ft_printf("-d option enable\n");
		if (*a + 1 < argc)
			*a = *a + 1;
		if (*a >= argc || (ft_str_is_digit(argv[*a]) == 0))
		{
			input->d = 0;
			return (1);
		}
		input->d = ft_atoi(argv[*a]);
		return (1);
	}
	if (ft_strcmp(argv[*a], "-n") == 0)
	{
		input->n = 1;
		ft_printf("Ncurses output mode\n");
		return (1);
	}
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

static	int		ft_check_arg(char **argv, t_input *input, int argc)
{
	int a;

	a = 1;
	while (argv[a])
	{
		if (ft_check_option(argv, input, &a, argc) == 0 && ft_check_player(argv[a], input) == 0)
		{
			ft_printf("Can't read source file %s\n", argv[a]);
			return (0);
		}
		a++;
	}
	return (1);
}

int				ft_check_error(int argc, char **argv, t_input *input)
{
	input->nb_p = 0;
	if (argc == 1)
	{
		ft_usage();
		return (0);
	}
	if (ft_check_arg(argv, input, argc) == 0)
		return (0);
	return (1);
}
