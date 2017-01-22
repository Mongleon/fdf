/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:32:43 by varichar          #+#    #+#             */
/*   Updated: 2016/11/05 14:54:58 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dest_end;
	size_t	i;

	i = 0;
	dest_end = ft_strlen(dest);
	while (src[i] != 0)
	{
		dest[dest_end + i] = src[i];
		i++;
	}
	dest[dest_end + i] = 0;
	return (dest);
}
