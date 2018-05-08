/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_cmdline_option.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 11:44:02 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 11:44:03 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "../libft/includes/libft.h"

int		ft_check_double_num(t_input *input)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	while (a < input->nb_p)
	{
		b = a + 1;
		while (b < input->nb_p)
		{
			if (input->num_player[a] == input->num_player[b]
				&& input->num_player[a] != INT_MIN_COR)
			{
				ft_printf("Error same champion number\n");
				return (0);
			}
			b++;
		}
		a++;
	}
	return (1);
}

int		ft_check_n_option(t_input *input)
{
	int a;

	a = -1;
	while (++a < 3)
	{
		if (input->num_player[a] != 0 &&
			ft_check_double_num(input) == 0)
		{
			ft_printf("Error champion number\n");
			return (0);
		}
	}
	return (1);
}

int		ft_check_ldump(char **argv, t_input *input, int *a, int argc)
{
	int er;

	er = 0;
	input->dl_nb = 0;
	if (*a + 1 < argc)
	{
		*a = *a + 1;
		input->dl_nb = ft_atoi_only(argv[*a], &er);
		if (er == 1 || input->dl_nb < 0)
		{
			ft_printf("Invalid number\n");
			return (0);
		}
		input->dl = 1;
	}
	else
	{
		ft_printf("Not enought arguments\n");
		return (0);
	}
	return (1);
}

int		ft_check_dump(char **argv, t_input *input, int *a, int argc)
{
	int er;

	er = 0;
	input->d_nb = 0;
	if (*a + 1 < argc)
	{
		*a = *a + 1;
		input->d_nb = ft_atoi_only(argv[*a], &er);
		if (er == 1 || input->d_nb < 0)
		{
			ft_printf("Invalid number\n");
			return (0);
		}
		input->d = 1;
	}
	else
	{
		ft_printf("Not enought arguments\n");
		return (0);
	}
	return (1);
}

int		ft_check_champ_num(char **argv, t_input *input,
										int *a, int argc)
{
	int er;
	int n;

	er = 0;
	if (*a + 1 < argc)
	{
		*a = *a + 1;
		n = ft_atoi_only(argv[*a], &er);
		if (input->num_player[input->nb_p] == INT_MIN_COR)
		{
			if (er == 1 || n < 0)
			{
				ft_printf("Invalid number\n");
				return (0);
			}
			input->num_player[input->nb_p] = n;
		}
	}
	if (*a + 1 >= argc)
	{
		ft_printf("No champion anymore\n");
		return (0);
	}
	return (1);
}
