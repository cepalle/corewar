/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 16:56:27 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 09:52:27 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef COREWAR_H
# define COREWAR_H

# define REG_CONTENT_SIZE 4

#include <stdlib.h>
#include <unistd.h>
#include "op.h"


typedef	struct		s_input
{
	int				n;
	char			*prog[4];
	int 			nb_p;
	int				d;
	t_header 		head[4];

}					t_input;

typedef	struct		s_cmd_save
{
//	t_cmd			cmd;
	char			codage_param;
	int				params[3];
	int				cycle_wating;
}					t_cmd_save;

typedef	struct		s_proc
{
	int				PC;
	int				carry;
	int 			reg[REG_NUMBER];
	t_cmd_save		cmd_save;
}					t_proc;

typedef	struct 		s_player
{
	t_header		head;
	unsigned int	last_live;
	unsigned int	live;
	t_proc			*process; // TODO test refg
	int				id;
}					t_player;

typedef	struct 		s_vm
{
	int 			nb_p;
	int				d;
	unsigned char 	tab[MEM_SIZE];
	t_player 		player[4];
//	unsigned int 	nb_process;
	t_proc			*process; // TODO test ref
	unsigned int 	nb_process;
	unsigned int 	len_process;
	unsigned int 	cycle;
}					t_vm;

typedef void (*t_cmd)(t_vm *vm, int num_player, int num_process);

void				ft_print_vm(t_vm *vm);
int					ft_check_error(int argc, char **argv, t_input *input);
void				ft_usage(void);
void				ft_create_map(t_vm *vm, t_input input);


/* PPICHIER */

void	ft_test_ppichier(t_vm *vm);
void 	ft_run_vm(t_vm *vm, int start);

#endif
