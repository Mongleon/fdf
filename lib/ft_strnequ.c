/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 03:08:10 by varichar          #+#    #+#             */
/*   Updated: 2016/11/05 14:32:09 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? 1 : 0);
	if (ft_strncmp(s1, s2, n))
		return (0);
	return (1);
}
