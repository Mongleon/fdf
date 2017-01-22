/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 10:58:34 by varichar          #+#    #+#             */
/*   Updated: 2017/01/04 09:31:26 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_nb(char *str, int n)
{
	int len;

	len = ((size_t)n > ft_strlen(str) || n < 0) ? ft_strlen(str) : n;
	write(1, str, len);
	return (len);
}
