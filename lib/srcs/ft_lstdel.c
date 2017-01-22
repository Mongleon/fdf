/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:33:47 by varichar          #+#    #+#             */
/*   Updated: 2016/11/04 09:29:47 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**todel;
	t_list	*buf;

	todel = alst;
	while (*alst)
	{
		buf = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = buf;
	}
	alst = NULL;
}
