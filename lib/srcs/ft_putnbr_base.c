/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:27:45 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 12:30:37 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long long n, int base, int prec, int maj)
{
	const char	basestr[17] = "0123456789abcdef";
	const char	basestrmaj[17] = "0123456789ABCDEF";
	int			wr;

	wr = 0;
	if (n == 0 && prec == 0)
		return (wr);
	if ((unsigned long long)n > 9223372036854775808ULL && (n = -n))
	{
		ft_putchar('-');
		wr++;
	}
	if (prec > 0)
		wr += ft_putnchar('0', prec - ft_nbrlen_base(n, base, 0) - ((int)n ==\
					0));
	if ((unsigned long long)n != 9223372036854775808ULL)
	{
		if ((n / base) > 0)
			wr += ft_putnbr_base(n / base, base, 0, maj);
		ft_putchar((maj) ? basestrmaj[(n % base)] : basestr[(n % base)]);
		wr++;
	}
	else
		wr += ft_putstr("-9223372036854775808");
	return (wr);
}
