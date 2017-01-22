/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 18:38:20 by varichar          #+#    #+#             */
/*   Updated: 2016/11/04 09:18:51 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (little[j] == 0)
			return (&((char*)big)[i]);
		j = 0;
		i++;
	}
	if (i >= len)
		return (NULL);
	if (big[i] == little[j])
		return (&((char*)big)[i]);
	return (NULL);
}
