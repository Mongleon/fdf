/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 00:16:42 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 20:27:05 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_args
{
	int			justify;
	int			sign;
	int			blank;
	int			aform;
	int			zero;
	int			field;
	int			precision;
	int			length;
	int			flag;
}				t_args;

void			init_arg(t_args **arg);
void			check_flags(char **format, t_args **arg);
void			check_field(char **format, t_args **arg, va_list ap);
void			check_prec(char **format, t_args **arg, va_list ap);
void			check_length(char **format, t_args **arg);
int				print_char(char **format, t_args **arg, va_list ap);
int				print_hexa(char **format, t_args **arg, va_list ap);
int				print_decimal(char **format, t_args **arg, va_list ap);
int				print_octal(char **format, t_args **arg, va_list ap);
int				print_modifier(char c, t_args *arg, int base, long long val);
int				pm_positive(char c, int mod, t_args **arg, long long val);
int				is_converter(char c);
int				is_flag(char c);
int				nbrlen_mod(long long val, int base, t_args *arg);
int				isnbpos(long long val, t_args *arg);
int				wstrlen_prec(wchar_t *str, int prec);

#endif
