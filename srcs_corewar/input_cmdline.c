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
#include "corewar.h"
#include <fcntl.h>

static	int		ft_check_player(char *argv, t_input *input)
{
	int		fd;
	size_t	len;

	len = ft_strlen(argv);
	if (len > 4 && ((ft_strncmp(argv + (len - 4), ".cor", 4) != 0)))
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Can't read source file %s\n", argv);
		return (0);
	}
	if (input->nb_p >= MAX_PLAYERS)
	{
		ft_printf("Too many players\n");
		return (0);
	}
	if (!ft_fill_player(input, fd))
		return (0);
	input->nb_p = input->nb_p + 1;
	close(fd);
	return (1);
}

static	int		ft_check_option(char **argv, t_input *input, int *a, int argc)
{
	if (ft_strcmp(argv[*a], "-n") == 0)
	{
		if (ft_check_champ_num(argv, input, a, argc) == 1)
			return (1);
	}
	else if (ft_strcmp(argv[*a], "-d") == 0)
	{
		if (ft_check_dump(argv, input, a, argc) == 1)
			return (1);
	}
	else if (ft_strcmp(argv[*a], "-dl") == 0)
	{
		if (ft_check_ldump(argv, input, a, argc) == 1)
			return (1);
	}
	else if (ft_strcmp(argv[*a], "-db") == 0)
	{
		input->db = 1;
		return (1);
	}
	return (0);
}

static	int		ft_check_arg(char **argv, t_input *input, int argc)
{
	int		a;
	size_t	len;

	a = 1;
	while (argv[a])
	{
		len = ft_strlen(argv[a]);
		if (len > 4 && ((ft_strncmp(argv[a] + (len - 4), ".cor", 4) == 0)))
		{
			if (ft_check_player(argv[a], input) == 0)
				return (0);
		}
		else if (ft_check_option(argv, input, &a, argc) == 0)
			return (0);
		if (a < argc)
			a++;
	}
	return (1);
}

static	void	input_cmd_line_init(t_input *input)
{
	int a;

	a = -1;
	input->nb_p = 0;
	input->db = 0;
	input->d = 0;
	input->d_nb = 0;
	while (++a < MAX_PLAYERS)
		input->num_player[a] = INT_MIN_COR;
}

int				input_cmdline(int argc, char **argv, t_input *input)
{
	input_cmd_line_init(input);
	if (argc == 1 || ft_check_arg(argv, input, argc) == 0 || input->nb_p == 0)
	{
		ft_usage();
		return (0);
	}
	if (ft_check_n_option(input) == 0)
		return (0);
	if (player_check_header(input) == 0)
	{
		ft_printf("Error player header\n");
		return (0);
	}
	if ((input->d == 1 && input->dl == 1))
	{
		ft_printf("Incompatible option '-d' and '-dl'\n");
		return (0);
	}
	return (1);
}
