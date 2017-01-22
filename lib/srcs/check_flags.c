/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 00:16:23 by varichar          #+#    #+#             */
/*   Updated: 2017/01/20 19:11:54 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	init_arg(t_args **arg)
{
	(*arg)->aform = 0;
	(*arg)->justify = 0;
	(*arg)->sign = 0;
	(*arg)->blank = 0;
	(*arg)->zero = 0;
	(*arg)->field = -1;
	(*arg)->precision = -1;
	(*arg)->length = 0;
	(*arg)->flag = 0;
}

void	check_flags(char **format, t_args **arg)
{
	while (**format == '#' || **format == '-' || **format == '+' ||\
			**format == ' ' || **format == '0')
	{
		if (**format == '#')
			(*arg)->aform = 1;
		if (**format == '-')
			(*arg)->justify = 1;
		if (**format == '+')
			(*arg)->sign = 1;
		if (**format == ' ')
			(*arg)->blank = 1;
		if (**format == '0')
			(*arg)->zero = 1;
		*format = *format + 1;
	}
	if ((*arg)->justify)
		(*arg)->zero = 0;
	if ((*arg)->sign)
		(*arg)->blank = 0;
}

void	check_field(char **format, t_args **arg, va_list ap)
{
	int wcard;

	wcard = -1;
	if (ft_isdigit(**format))
	{
		(*arg)->field = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format = *format + 1;
	}
	else if (**format == '*')
	{
		wcard = va_arg(ap, int);
		(*arg)->field = (wcard >= 0) ? wcard : wcard * -1;
		if (wcard < 0)
			(*arg)->justify = 1;
		*format = *format + 1;
	}
	else if (ft_isdigit(**format))
		*format += 1;
	if (ft_isdigit(**format) || **format == '*')
		check_field(format, arg, ap);
	if ((*arg)->field == -1)
		(*arg)->field = 0;
}

void	check_prec(char **format, t_args **arg, va_list ap)
{
	int	wcard;

	if (**format == '.')
	{
		*format = *format + 1;
		if (ft_isdigit(**format))
		{
			(*arg)->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				*format = *format + 1;
		}
		else if (**format == '*')
		{
			wcard = va_arg(ap, int);
			(*arg)->precision = (wcard >= 0) ? wcard : -1;
			*format = *format + 1;
		}
		else
			(*arg)->precision = 0;
	}
}

void	check_length(char **format, t_args **arg)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||\
			**format == 'z')
	{
		if (**format == 'h')
			(*arg)->length = 2;
		if (**format == 'l')
			(*arg)->length = 3;
		if (**format == 'j')
			(*arg)->length = 5;
		if (**format == 'z')
			(*arg)->length = 6;
		*format += 1;
	}
	if (**format == 'h' || **format == 'l')
	{
		if (**format == 'h' && *(*format - 1) == 'h')
			(*arg)->length = 1;
		if (**format == 'l' && *(*format - 1) == 'l')
			(*arg)->length = 4;
		*format += 1;
	}
}
