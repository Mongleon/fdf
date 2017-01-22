/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:08:11 by varichar          #+#    #+#             */
/*   Updated: 2016/11/05 11:15:44 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	if ((dest = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
	{
		while (s[i] != 0)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = 0;
	}
	return (dest);
}
