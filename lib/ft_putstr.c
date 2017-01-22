/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 04:18:45 by varichar          #+#    #+#             */
/*   Updated: 2017/01/05 09:52:18 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *s)
{
	int len;

	len = ft_strlen(s);
	if (s)
		write(1, s, len);
	return (len);
}
