/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:15:51 by varichar          #+#    #+#             */
/*   Updated: 2016/12/15 14:36:35 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 64

typedef struct			s_gnl_list
{
	char				*content;
	int					fd;
	struct s_gnl_list	*next;
}						t_glist;

int						get_next_line(const int fd, char **line);

#endif
