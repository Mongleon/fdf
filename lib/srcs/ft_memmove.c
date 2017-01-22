/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 15:15:26 by varichar          #+#    #+#             */
/*   Updated: 2016/08/07 01:28:54 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = (void*)malloc(n);
	if (tmp)
	{
		while (i < n)
		{
			((char*)tmp)[i] = ((char*)src)[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			((char*)dest)[i] = ((char*)tmp)[i];
			i++;
		}
		free(tmp);
	}
	return (dest);
}
