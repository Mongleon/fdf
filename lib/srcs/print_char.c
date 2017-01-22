/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:25:49 by varichar          #+#    #+#             */
/*   Updated: 2017/01/20 19:07:49 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_null(char c, t_args **arg)
{
	int	towr;
	int	len;

	len = 0;
	if (c == 's' && (*arg)->length != 3)
	{
		towr = (*arg)->field - (((*arg)->precision > 6 || (*arg)->precision\
					< 0) ? 6 : (*arg)->precision);
		len += ft_putnchar(((*arg)->zero) ? '0' : ' ', ((*arg)->justify) ? 0 :\
					towr);
		len += ft_putstr_nb("(null)", (*arg)->precision);
	}
	else
	{
		towr = (*arg)->field - 6;
		len += ft_putnchar(' ', ((*arg)->justify) ? 0 : towr);
		len += ft_putstr("(null)");
	}
	return (len);
}

int		check_wstring(char c, t_args **arg, va_list ap)
{
	int		len;
	wchar_t	*str;
	int		towr;

	len = 0;
	if ((c == 's' && (*arg)->length == 3) || c == 'S')
	{
		if ((str = va_arg(ap, wchar_t*)))
		{
			towr = (*arg)->field - (((*arg)->precision > ft_wstrlen(str) ||\
			(*arg)->precision < 0) ? ft_wstrlen(str) :\
					wstrlen_prec(str, (*arg)->precision));
			len += ft_putnchar(((*arg)->zero) ? '0' : ' ',\
					((*arg)->justify) ? 0 : towr);
			if ((*arg)->precision >= 0)
				len += ft_putwstr_nb(str, (*arg)->precision);
			else
				len += ft_putwstr_nb(str, ft_wstrlen(str));
		}
		else
			len += check_null(c, arg);
	}
	return (len);
}

int		check_string(char c, t_args **arg, va_list ap)
{
	int		len;
	char	*str;
	int		towr;

	len = 0;
	if (c == 's' && (*arg)->length != 3)
	{
		if ((str = va_arg(ap, char*)))
		{
			towr = (*arg)->field - (((*arg)->precision > (int)ft_strlen(str) ||\
			(*arg)->precision < 0) ? ft_strlen(str) : (*arg)->precision);
			len += ft_putnchar(((*arg)->zero) ? '0' : ' ',\
					((*arg)->justify) ? 0 : towr);
			len += ft_putstr_nb(str, (*arg)->precision);
		}
		else
			len += check_null(c, arg);
	}
	return (len);
}

int		check_char(char c, t_args **arg, va_list ap)
{
	int len;

	len = 0;
	if (c == 'c' || c == 'C')
	{
		len += ft_putnchar(((*arg)->zero) ? '0' : ' ',\
				((*arg)->justify) ? 0 : (*arg)->field - 1);
		if ((*arg)->length == 3 || c == 'C')
			len += ft_putwchar(va_arg(ap, wchar_t));
		else
		{
			ft_putchar((unsigned char)va_arg(ap, int));
			len++;
		}
	}
	else if (c == '%')
	{
		len += 1;
		len += ft_putnchar(((*arg)->zero) ? '0' : ' ',\
				((*arg)->justify) ? 0 : (*arg)->field - 1);
		ft_putchar('%');
	}
	return (len);
}

int		print_char(char **format, t_args **arg, va_list ap)
{
	int wr;

	wr = 0;
	if ((**format == 's' || **format == 'S' || **format == 'c' ||\
			**format == 'C' || **format == '%') && !(*arg)->flag)
	{
		wr += check_char(**format, arg, ap);
		wr += check_string(**format, arg, ap);
		wr += check_wstring(**format, arg, ap);
		wr += ft_putnchar(' ', ((*arg)->justify) ? (*arg)->field - wr : 0);
		*format += 1;
		(*arg)->flag = 1;
	}
	return (wr);
}
