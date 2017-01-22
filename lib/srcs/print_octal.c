/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:07:49 by varichar          #+#    #+#             */
/*   Updated: 2017/01/20 19:07:17 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_octal(char c, t_args **arg, va_list ap)
{
	int			len;
	long long	val;

	len = 0;
	val = va_arg(ap, long long);
	len += ft_putnchar(' ', (!(*arg)->justify && !(*arg)->zero)\
			? (*arg)->field - ft_nbrlen_base(val, 8, (*arg)->precision) - \
			(*arg)->aform : 0);
	if ((*arg)->aform && (val != 0 || (*arg)->precision == 0))
	{
		len += ft_putstr("0");
		(*arg)->precision -= ((*arg)->precision > 1) ? 1 : 0;
	}
	len += print_modifier(c, (*arg), 8, val);
	len += ft_putnchar(' ', ((*arg)->justify)\
		? (*arg)->field - len : 0);
	return (len);
}

int		print_octal(char **format, t_args **arg, va_list ap)
{
	int		wr;
	char	fld;

	wr = 0;
	fld = (!(*arg)->zero) ? ' ' : '0';
	if ((**format == 'o' || **format == 'O') && !(*arg)->flag)
	{
		wr += check_octal(**format, arg, ap);
		*format += 1;
		(*arg)->flag = 1;
	}
	else if (!is_converter(**format) && !(*arg)->flag && !is_flag(**format) && \
			**format)
	{
		wr += ft_putnchar(fld, (!(*arg)->justify) ? (*arg)->field - 1 : 0);
		ft_putchar(**format);
		wr++;
		wr += ft_putnchar(' ', ((*arg)->justify) ? (*arg)->field - 1 : 0);
		*format += 1;
	}
	return (wr);
}
