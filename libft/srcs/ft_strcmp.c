/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:41:52 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:41:54 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}
