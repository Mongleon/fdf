/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:16:48 by varichar          #+#    #+#             */
/*   Updated: 2017/01/15 16:51:12 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_base(unsigned long long n, int base, int prec, int maj)
{
	const char	basestr[17] = "0123456789abcdef";
	const char	basestrmaj[17] = "0123456789ABCDEF";
	int			wr;

	wr = 0;
	if (n == 0 && prec == 0)
		return (0);
	if (prec > 0)
	{
		wr += ft_putnchar('0', prec - ft_nbrlen_base(n, base, 0));
	}
	if ((n / base) > 0)
		wr += ft_putunbr_base(n / base, base, 0, maj);
	ft_putchar((maj) ? basestrmaj[(n % base)] : basestr[(n % base)]);
	return (++wr);
}
