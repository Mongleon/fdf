/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 11:58:32 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 14:30:23 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrlen(wchar_t *str)
{
	int len;
	int	nb;

	len = -1;
	nb = 0;
	if (str)
		while (str[++len])
		{
			if (str[len] <= 0x7F)
				nb += 1;
			else if (str[len] <= 0x7FF)
				nb += 2;
			else if (str[len] <= 0xFFFF)
				nb += 3;
			else if (str[len] <= 0x10FFFF)
				nb += 4;
		}
	return (nb);
}
