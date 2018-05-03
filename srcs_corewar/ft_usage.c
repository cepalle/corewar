/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:53:28 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:53:30 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

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
