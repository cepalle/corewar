/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:03:50 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:15:40 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	pf_print_next_arg(const char *format, int *i, va_list *ap)
{
	char		*str_arg;
	t_format	fm;

	(*i)++;
	fm = pf_get_format(format, i);
	pf_handler_format(&fm);
	str_arg = pf_arg_to_str(&fm, ap);
	if (fm.type == 'c')
		return (pf_print_arg_c(&fm, str_arg));
	else if (fm.type == 's')
		return (pf_print_arg_s(&fm, str_arg));
	else if (fm.type == 'd')
		return (pf_print_arg_i(&fm, str_arg));
	else if (fm.type == '%')
		return (pf_print_not_arg(&fm, str_arg));
	else if (fm.type == 'p')
		return (pf_print_arg_p(&fm, str_arg));
	else if (fm.type == 'o' || fm.type == 'u' ||
			fm.type == 'x' || fm.type == 'X')
		return (pf_print_arg_oux(&fm, str_arg));
	else
		return (pf_print_not_type(&fm, str_arg));
}

int	pf_printf_aux(const char *format, va_list *ap)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			pf_putchar(format[i]);
			length++;
			i++;
		}
		else
			length += pf_print_next_arg(format, &i, ap);
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	unsigned	length;

	va_start(ap, format);
	length = pf_printf_aux(format, &ap);
	va_end(ap);
	return (length);
}
