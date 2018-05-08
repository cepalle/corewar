/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_cmdline_player.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@studen.le-101.fr>       +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 11:49:53 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 11:49:54 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "../libft/includes/libft.h"

int		ft_fill_player(t_input *input, int fd)
{
	ssize_t	ret;

	ret = read(fd, &input->head[input->nb_p], sizeof(t_header));
	if (ret != sizeof(t_header))
	{
		ft_printf("Error read header\n");
		return (0);
	}
	swap_4(&input->head[input->nb_p].magic);
	swap_4(&input->head[input->nb_p].prog_size);
	input->prog[input->nb_p] = ft_memalloc(sizeof(char) *
								input->head[input->nb_p].prog_size + 1);
	ret = read(fd, input->prog[input->nb_p],
			input->head[input->nb_p].prog_size + 1);
	if (ret != input->head[input->nb_p].prog_size)
	{
		ft_printf("Error read prog\n");
		return (0);
	}
	return (1);
}

int		player_check_header(t_input *input)
{
	unsigned int a;

	a = 0;
	while (a < input->nb_p)
	{
		if (input->head[a].prog_size > CHAMP_MAX_SIZE ||
			input->head[a].prog_size == 0)
			return (0);
		if (ft_strlen(input->head[a].prog_name) == 0 ||
			ft_strlen(input->head[a].prog_name) > PROG_NAME_LENGTH)
			return (0);
		if (input->head[a].magic != COREWAR_EXEC_MAGIC)
			return (0);
		if (ft_strlen(input->head[a].comment) > COMMENT_LENGTH)
			return (0);
		a++;
	}
	return (1);
}
