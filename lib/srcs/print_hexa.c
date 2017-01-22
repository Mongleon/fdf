/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:14:22 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 15:56:54 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		check_p(char c, t_args **arg, va_list ap)
{
	int				len;
	unsigned long	val;
	int				prec;

	len = 0;
	if (c == 'p')
	{
		val = (unsigned long)va_arg(ap, void*);
		prec = ((*arg)->precision >= 0) ? (*arg)->precision : (*arg)->field - \
			ft_nbrlen_base(val, 16, -1) - 2 + (val == 0);
		len += ft_putnchar(' ', (!(*arg)->justify && !(*arg)->zero) ? \
				(*arg)->field - ft_nbrlen_base(val, 16, -1) - 2 : 0);
		len += ft_putstr("0x");
		len += ft_putnbr_base(val, 16, ((*arg)->zero || \
					(*arg)->precision >= 0) ? prec : -1, 0);
		len += ft_putnchar(' ', ((*arg)->justify) ? (*arg)->field -\
				ft_nbrlen_base(val, 16, -1) - 2 : 0);
	}
	return (len);
}

int		check_xmaj(char c, t_args **arg, va_list ap)
{
	int				len;
	long long		val;

	len = 0;
	if (c == 'X')
	{
		val = va_arg(ap, long long);
		len += ft_putnchar(' ', (!(*arg)->justify && !(*arg)->zero)\
				? (*arg)->field - ft_nbrlen_base(val, 16, (*arg)->precision)\
				- ((*arg)->aform * 2) : 0);
		if ((*arg)->aform && val != 0)
			len += ft_putstr("0X");
		len += print_modifier(c, (*arg), 16, val);
		len += ft_putnchar(' ', ((*arg)->justify)\
				? (*arg)->field - len : 0);
	}
	return (len);
}

int		check_x(char c, t_args **arg, va_list ap)
{
	int				len;
	long long		val;

	len = 0;
	if (c == 'x')
	{
		val = va_arg(ap, long long);
		len += ft_putnchar(' ', (!(*arg)->justify && !(*arg)->zero)\
				? (*arg)->field - ft_nbrlen_base(val, 16, (*arg)->precision)\
				- ((*arg)->aform * 2) : 0);
		if ((*arg)->aform && val != 0)
			len += ft_putstr("0x");
		len += print_modifier(c, (*arg), 16, val);
		len += ft_putnchar(' ', ((*arg)->justify)\
				? (*arg)->field - len : 0);
	}
	return (len);
}

int		print_hexa(char **format, t_args **arg, va_list ap)
{
	int	wr;

	wr = 0;
	if ((**format == 'p' || **format == 'X' || **format == 'x') && \
			!(*arg)->flag)
	{
		wr += check_p(**format, arg, ap);
		wr += check_x(**format, arg, ap);
		wr += check_xmaj(**format, arg, ap);
		*format += 1;
		(*arg)->flag = 1;
	}
	return (wr);
}
