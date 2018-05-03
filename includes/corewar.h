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

# include <stdlib.h>
# include <unistd.h>
# include "op.h"

struct		s_input
{
	int				n;
	char			*prog[4];
	int 			nb_p;
	int				d;
	t_header 		head[4];
};
typedef struct		s_input t_input;

struct		s_cmd_save
{
	void			*cmd;
	char			codage_param;
	int				params[3];
	int				cycle_wating;
};
typedef struct		s_cmd_save t_cmd_save;

struct 		s_player
{
	t_header		head;
	unsigned int	last_live;
	unsigned int	live;
	int				id;
};
typedef struct		s_player t_player;

struct		s_proc
{
	int				PC;
	int				carry;
	int 			reg[REG_NUMBER];
	t_cmd_save		cmd_save;
};
typedef struct		s_proc t_proc;

struct		s_vm
{
	int 			nb_p;
	int				d;
	unsigned char 	tab[MEM_SIZE];
	t_player 		player[4];
	t_proc			*process; // TODO test ref
	unsigned int 	nb_process;
	unsigned int 	len_process;
	unsigned int 	cycle;
};
typedef struct s_vm t_vm;

typedef void (*t_cmd)(t_vm *vm, t_proc *proc);

/*
** ???
*/

int			input_cmdline(int argc, char **argv, t_input *input);
void		vm_init(t_vm *vm, t_input input);
void		vm_run(t_vm *vm);
void		vm_cycle(t_vm *vm);
void		vm_print(t_vm vm);
void		proc_exec(t_vm *vm, t_proc *proc);

/*
** UTILS
*/

int			ft_str_is_digit(char *str);
void		ft_usage(void);

/*
** CMD
*/

int		cmd_add(t_vm *vm, t_proc *proc);
int		cmd_aff(t_vm *vm, t_proc *proc);
int		cmd_and(t_vm *vm, t_proc *proc);
int		cmd_fork(t_vm *vm, t_proc *proc);
int		cmd_ld(t_vm *vm, t_proc *proc);
int		cmd_ldi(t_vm *vm, t_proc *proc);
int		cmd_lfork(t_vm *vm, t_proc *proc);
int		cmd_live(t_vm *vm, t_proc *proc);
int		cmd_lld(t_vm *vm, t_proc *proc);
int		cmd_lldi(t_vm *vm, t_proc *proc);
int		cmd_or(t_vm *vm, t_proc *proc);
int		cmd_st(t_vm *vm, t_proc *proc);
int		cmd_sti(t_vm *vm, t_proc *proc);
int		cmd_sub(t_vm *vm, t_proc *proc);
int		cmd_xor(t_vm *vm, t_proc *proc);
int		cmd_zjmp(t_vm *vm, t_proc *proc);

#endif
