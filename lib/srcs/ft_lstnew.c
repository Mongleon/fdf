/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:10:26 by varichar          #+#    #+#             */
/*   Updated: 2016/11/05 13:42:56 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	content_size = (content == NULL) ? 0 : content_size;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		if (content != NULL)
		{
			new->content = (void*)malloc(content_size);
			ft_memcpy(new->content, content, content_size);
		}
		else
		{
			new->content = NULL;
		}
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
