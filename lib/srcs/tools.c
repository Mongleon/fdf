/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:02:27 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 20:28:15 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_converter(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||\
			c == 'X' || c == 'D' || c == 'O' || c == 'U' || c == 'c' ||\
			c == 'C' || c == 's' || c == 'S' || c == 'p' || c == '%');
}

int		is_flag(char c)
{
	return (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0' ||\
			c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == '.' ||\
			c == '*' || ft_isdigit(c));
}

int		nbrlen_mod(long long val, int base, t_args *arg)
{
	int len;
	int mod;

	len = 0;
	mod = arg->length;
	if (mod == 0)
		len += ft_nbrlen_base((int)val, base, arg->precision);
	if (mod == 1)
		len += ft_nbrlen_base((signed char)val, base, arg->precision);
	if (mod == 2)
		len += ft_nbrlen_base((short)val, base, arg->precision);
	if (mod == 3)
		len += ft_nbrlen_base((long)val, base, arg->precision);
	if (mod == 4)
		len += ft_nbrlen_base(val, base, arg->precision);
	if (mod == 5)
		len += ft_nbrlen_base((intmax_t)val, base, arg->precision);
	if (mod == 6)
		len += ft_nbrlen_base((size_t)val, base, arg->precision);
	return (len);
}

int		isnbpos(long long val, t_args *arg)
{
	int mod;

	mod = arg->length;
	if (mod == 0)
		return ((int)val >= 0);
	if (mod == 1)
		return ((signed char)val >= 0);
	if (mod == 2)
		return ((short)val >= 0);
	if (mod == 3)
		return ((long)val >= 0);
	if (mod == 4)
		return (val >= 0);
	if (mod == 5)
		return ((intmax_t)val >= 0);
	if (mod == 6)
		return ((size_t)val > 0);
	return (0);
}

int		wstrlen_prec(wchar_t *str, int prec)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	ret = 0;
	len = 0;
	while ((len < prec || prec < 0) && str[i])
	{
		len += ft_wcharlen(str[i]);
		if (len <= prec)
			ret += ft_wcharlen(str[i]);
		i++;
	}
	return (ret);
}
