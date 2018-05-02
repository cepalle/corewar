/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_s_to_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:01:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:44 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t	*pf_wstrdup(wchar_t *wstr)
{
	int		i;
	wchar_t	*to_do;

	i = 0;
	while (wstr[i])
		i++;
	to_do = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1));
	i = 0;
	while (wstr[i])
	{
		to_do[i] = wstr[i];
		i++;
	}
	to_do[i] = 0;
	return (to_do);
}

wchar_t	*pf_wstrndup(wchar_t *wstr, int precision)
{
	wchar_t *to_do;
	int		i;
	int		len;

	to_do = (wchar_t *)pf_memalloc(sizeof(wchar_t) * (precision + 1));
	len = 0;
	i = 0;
	while (wstr[i] && len + pf_size_wc(wstr[i]) <= precision)
	{
		to_do[i] = wstr[i];
		len += pf_size_wc(wstr[i]);
		i++;
	}
	return (to_do);
}

char	*pf_arg_ls_to_str(t_format *fm, va_list *ap)
{
	wchar_t	*wstr;
	int		precision;

	precision = fm->precision;
	wstr = (wchar_t *)va_arg(*ap, wchar_t *);
	if (fm->precision == 0)
		return (pf_strnew(0));
	if (!wstr)
	{
		fm->lenght = '\0';
		return (pf_strdup("(null)"));
	}
	if (precision < 0)
		return ((char *)pf_wstrdup(wstr));
	return ((char *)pf_wstrndup(wstr, fm->precision));
}

char	*pf_arg_s_to_str(t_format *fm, va_list *ap)
{
	char	*str;
	char	*to_do;
	int		precision;
	int		i;

	if (fm->lenght == 'l')
		return (pf_arg_ls_to_str(fm, ap));
	precision = fm->precision;
	str = (char *)va_arg(*ap, char *);
	if (fm->precision == 0)
		return (pf_strnew(0));
	if (!str)
		return (pf_strdup("(null)"));
	if (precision < 0)
		return (pf_strdup(str));
	to_do = pf_strnew(precision);
	i = 0;
	while (i < precision && str[i])
	{
		to_do[i] = str[i];
		i++;
	}
	return (to_do);
}
