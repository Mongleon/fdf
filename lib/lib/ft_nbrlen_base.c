/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:35:43 by varichar          #+#    #+#             */
/*   Updated: 2017/01/16 19:09:34 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_base(long long n, int base, int prec)
{
	int len;

	len = 0;
	if (n == 0 && prec == 0)
		return (0);
	if ((unsigned long long)n > 9223372036854775808ULL && (n = -n))
		len++;
	if (prec > 0 && prec >= ft_nbrlen_base(n, base, 0))
	{
		len += prec - ft_nbrlen_base(n, base, 0);
		len -= ((int)n == 0) ? 1 : 0;
		prec = 0;
	}
	if ((unsigned long long)n != 9223372036854775808ULL)
	{
		if ((n / base) > 0)
			len += ft_nbrlen_base(n / base, base, prec);
	}
	else
		return (20);
	return (++len);
}
