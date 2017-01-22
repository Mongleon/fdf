/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 01:45:36 by varichar          #+#    #+#             */
/*   Updated: 2016/11/04 12:43:57 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(unsigned long size)
{
	char *str;

	if ((str = (char*)ft_memalloc(size + 1)))
	{
		str[size] = 0;
		return (str);
	}
	return (NULL);
}
