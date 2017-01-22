/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:40:25 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 07:34:59 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_di(char c, t_args **arg, va_list ap)
{
	int			len;
	int			pos;
	long long	val;

	len = 0;
	val = va_arg(ap, long long);
	pos = ((((*arg)->sign || (*arg)->blank)) && isnbpos(val, *arg)) ? 1 : 0;
	len += ft_putnchar(' ', !(*arg)->justify && ((!(*arg)->zero ||\
			(*arg)->precision != -1)) ? (*arg)->field - nbrlen_mod(val, 10,\
			*arg) - pos : 0);
	len += pm_positive(c, (*arg)->length, arg, val);
	len += print_modifier(c, (*arg), 10, val);
	len += ft_putnchar(' ', ((*arg)->justify)\
		? (*arg)->field - len : 0);
	return (len);
}

int		check_udi(char c, t_args **arg, va_list ap)
{
	int			len;
	long long	val;

	len = 0;
	val = va_arg(ap, unsigned long long);
	len += ft_putnchar(' ', !(*arg)->justify && ((!(*arg)->zero ||\
			(*arg)->precision != -1)) ? (*arg)->field - ft_nbrlen_base(val, 10,\
			(*arg)->precision) : 0);
	len += print_modifier(c, (*arg), 10, val);
	len += ft_putnchar(' ', ((*arg)->justify)\
		? (*arg)->field - len : 0);
	return (len);
}

int		print_decimal(char **format, t_args **arg, va_list ap)
{
	int	wr;

	wr = 0;
	if ((**format == 'd' || **format == 'i' || **format == 'D' ||\
			**format == 'u' || **format == 'U') && !(*arg)->flag)
	{
		if (**format == 'd' || **format == 'i' || **format == 'D')
			wr += check_di(**format, arg, ap);
		if (**format == 'u' || **format == 'U')
			wr += check_udi(**format, arg, ap);
		*format += 1;
		(*arg)->flag = 1;
	}
	return (wr);
}
