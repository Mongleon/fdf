/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:09:15 by varichar          #+#    #+#             */
/*   Updated: 2016/12/11 14:38:15 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_glist	*gnl_lstnew(char const *content, int fd)
{
	t_glist	*lst;

	if ((lst = (t_glist*)malloc(sizeof(t_glist))))
	{
		lst->content = NULL;
		lst->fd = fd;
		if (content)
		{
			if ((lst->content = ft_strdup(content)))
				return (NULL);
		}
		lst->next = NULL;
	}
	return (lst);
}

static int		gnl_bufcheck(char **line, t_glist *lst)
{
	char	*tmp;
	char	*todel;
	int		i;

	if (lst->content)
	{
		todel = *line;
		if ((tmp = ft_strchr(lst->content, '\n')))
		{
			i = tmp - lst->content;
			tmp = ft_strsub(lst->content, 0, i);
			*line = ft_strjoin(*line, tmp);
			ft_strdel(&tmp);
			tmp = ft_strdup(lst->content + i + 1);
			ft_strdel(&(lst->content));
			lst->content = tmp;
			free(todel);
			return (1);
		}
		*line = ft_strjoin(*line, lst->content);
		ft_strdel(&(lst->content));
		free(todel);
	}
	return (0);
}

static	int		ft_cheatnorm(t_glist *lst, char **line)
{
	int		rd;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		i;
	char	*todel;

	rd = read(lst->fd, buf, BUFF_SIZE);
	buf[rd] = 0;
	todel = *line;
	if ((tmp = ft_strchr(buf, '\n')))
	{
		i = tmp - buf;
		tmp = ft_strsub(buf, 0, i);
		*line = ft_strjoin(*line, tmp);
		ft_strdel(&tmp);
		lst->content = ft_strdup(buf + i + 1);
		free(todel);
		return (-2);
	}
	*line = ft_strjoin(*line, buf);
	free(todel);
	return (rd);
}

static int		gnl_reader(t_glist *lst, char **line)
{
	int		rd;

	while ((rd = ft_cheatnorm(lst, line)) > 0)
		;
	if (!*line || (rd == 0 && **line == 0) || rd == -1)
	{
		ft_strdel(&lst->content);
		return ((rd == -1) ? -1 : 0);
	}
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_glist	*beginlist = NULL;
	t_glist			*lst;
	char			tmp;

	if (!line || read(fd, &tmp, 0) == -1 || fd < 0)
		return (-1);
	if (*line)
		*line = NULL;
	lst = beginlist;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (!lst)
	{
		lst = gnl_lstnew(NULL, fd);
		lst->next = beginlist;
		beginlist = lst;
	}
	else if (gnl_bufcheck(line, lst))
		return (1);
	return (gnl_reader(lst, line));
}
