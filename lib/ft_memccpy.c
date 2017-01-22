/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:54:56 by varichar          #+#    #+#             */
/*   Updated: 2016/11/05 11:08:32 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] == (unsigned char)c)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			return ((void*)&((unsigned char*)dest)[i + 1]);
		}
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (NULL);
}
