/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:05:16 by varichar          #+#    #+#             */
/*   Updated: 2016/11/05 13:44:10 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*returnable;
	t_list	*new_lst;

	if (lst != NULL)
	{
		if ((new_lst = f(lst)))
			lst = lst->next;
		returnable = &(*new_lst);
		while (lst)
		{
			new_lst->next = f(lst);
			lst = lst->next;
			new_lst = new_lst->next;
		}
		new_lst->next = NULL;
		return (returnable);
	}
	return (NULL);
}
