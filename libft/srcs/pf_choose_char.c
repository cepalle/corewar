/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choose_char.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:02:21 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:40:01 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	pf_choose_ou_char(unsigned c)
{
	return ('0' + c);
}

char	pf_choose_x_char(unsigned c)
{
	if (c < 10)
		return ('0' + c);
	return ('a' + c - 10);
}

char	pf_choose_xx_char(unsigned c)
{
	if (c < 10)
		return ('0' + c);
	return ('A' + c - 10);
}
