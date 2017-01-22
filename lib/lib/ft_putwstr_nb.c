/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:34:39 by varichar          #+#    #+#             */
/*   Updated: 2017/01/19 19:49:09 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr_nb(wchar_t *str, int nb)
{
	int	i;
	int	ret;
	int	len;

	i = 0;
	ret = 0;
	len = 0;
	while ((len < nb || nb < 0) && str[i])
	{
		len += ft_wcharlen(str[i]);
		if (len <= nb)
			ret += ft_putwchar(str[i]);
		i++;
	}
	return (ret);
}
