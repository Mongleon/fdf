/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 23:54:56 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 13:49:17 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	dispvar(char **format, va_list ap)
{
	int		wr;
	t_args	*arg;

	wr = 0;
	arg = (t_args*)malloc(sizeof(t_args));
	*format += 1;
	if (**format != 0)
	{
		init_arg(&arg);
		while (is_flag(**format))
		{
			check_flags(format, &arg);
			check_field(format, &arg, ap);
			check_prec(format, &arg, ap);
			check_length(format, &arg);
		}
		wr += print_char(format, &arg, ap);
		wr += print_hexa(format, &arg, ap);
		wr += print_decimal(format, &arg, ap);
		wr += print_octal(format, &arg, ap);
	}
	free(arg);
	return (wr);
}

int	recurs(char **format, va_list ap, int written)
{
	char *chr;

	if (**format == '%')
	{
		written += dispvar(format, ap);
		chr = *format;
		return (recurs(&chr, ap, written));
	}
	else if ((chr = ft_strchr(*format, '%')))
	{
		written += write(1, *format, chr - *format);
		return (recurs(&chr, ap, written));
	}
	else if ((chr = ft_strchr(*format, '\0')))
	{
		written += write(1, *format, chr - *format);
		return (written);
	}
	return (-1);
}

int	ft_printf(const char *restrict format, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, format);
	ret = recurs((char**)&format, ap, 0);
	va_end(ap);
	return (ret);
}
