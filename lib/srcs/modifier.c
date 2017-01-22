/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:59:53 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 16:46:40 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pm_putsign(t_args **arg)
{
	ft_putchar(' ' * (*arg)->blank + '+' * (*arg)->sign);
	if (!(*arg)->justify)
		(*arg)->field--;
	return (1);
}

int		pm_positive(char c, int mod, t_args **arg, long long val)
{
	int	len;

	len = 0;
	if (c == 'i' || c == 'd' || c == 'D')
	{
		if (((*arg)->blank || (*arg)->sign) && mod == 0 && (int)val >= 0)
			len += pm_putsign(arg);
		if (((*arg)->blank || (*arg)->sign) && mod == 1 && (signed char)val >=\
				0)
			len += pm_putsign(arg);
		if (((*arg)->blank || (*arg)->sign) && mod == 2 && (short)val >= 0)
			len += pm_putsign(arg);
		if (((*arg)->blank || (*arg)->sign) && mod == 3 && (long)val >= 0)
			len += pm_putsign(arg);
		if (((*arg)->blank || (*arg)->sign) && mod == 4 && val >= 0)
			len += pm_putsign(arg);
		if (((*arg)->blank || (*arg)->sign) && mod == 5 && (intmax_t)val >= 0)
			len += pm_putsign(arg);
		if (((*arg)->blank || (*arg)->sign) && mod == 6 && (size_t)val > 0)
			len += pm_putsign(arg);
	}
	return (len);
}

int		pm_signed(char c, t_args *arg, int base, long long val)
{
	int len;
	int mod;

	len = 0;
	mod = (c == 'D') ? 3 : arg->length;
	if (mod == 0)
		len += ft_putnbr_base((int)val, base, arg->precision, 0);
	if (mod == 1)
		len += ft_putnbr_base((signed char)val, base, arg->precision, 0);
	if (mod == 2)
		len += ft_putnbr_base((short)val, base, arg->precision, 0);
	if (mod == 3)
		len += ft_putnbr_base((long)val, base, arg->precision, 0);
	if (mod == 4)
		len += ft_putnbr_base(val, base, arg->precision, 0);
	if (mod == 5)
		len += ft_putnbr_base((intmax_t)val, base, arg->precision, 0);
	if (mod == 6)
		len += ft_putnbr_base((size_t)val, base, arg->precision, 0);
	return (len);
}

int		pm_unsigned(char c, t_args *arg, int base, unsigned long long val)
{
	int len;
	int maj;
	int mod;

	len = 0;
	mod = ((c == 'O' || c == 'U')) ? 3 : arg->length;
	maj = (c == 'X') ? 1 : 0;
	if (mod == 0)
		len += ft_putunbr_base((unsigned int)val, base, arg->precision, maj);
	if (mod == 1)
		len += ft_putunbr_base((unsigned char)val, base, arg->precision, maj);
	if (mod == 2)
		len += ft_putunbr_base((unsigned short)val, base, arg->precision, maj);
	if (mod == 3)
		len += ft_putunbr_base((unsigned long)val, base, arg->precision, maj);
	if (mod == 4)
		len += ft_putunbr_base((unsigned long long)val, base, arg->precision,\
				maj);
	if (mod == 5)
		len += ft_putunbr_base((uintmax_t)val, base, arg->precision, maj);
	if (mod == 6)
		len += ft_putunbr_base((size_t)val, base, arg->precision, maj);
	return (len);
}

int		print_modifier(char c, t_args *arg, int base, long long val)
{
	int	len;

	len = 0;
	if (c == 'i' || c == 'd' || c == 'D')
	{
		if (arg->precision < 0)
			arg->precision = (!arg->zero) ? -1 : arg->field - arg->aform * 2\
			- !isnbpos(val, arg);
		len += pm_signed(c, arg, base, val);
	}
	if (c == 'o' || c == 'u' || c == 'O' || c == 'U' || c == 'x' || c == 'X')
	{
		if (arg->precision < 0)
			arg->precision = (!arg->zero) ? -1 : arg->field - arg->aform * 2;
		len += pm_unsigned(c, arg, base, val);
	}
	return (len);
}
