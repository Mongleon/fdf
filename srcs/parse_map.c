/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:51:36 by varichar          #+#    #+#             */
/*   Updated: 2017/04/12 17:58:35 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		nbline(char *mapfile)
{
	int		nb;
	int		fd;
	char	*line;

	nb = 0;
	fd = open(mapfile, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nb++;
	}
	close(fd);
	return (nb);
}

int		nb_words(char *line)
{
	int	w;
	int	nb;

	w = 0;
	nb = 0;
	while (*line)
	{
		if (*line == ' ')
			w = 0;
		else if ((ft_isdigit(*line) || *line == '-') && w == 0)
		{
			nb++;
			w = 1;
		}
		else if (!ft_isdigit(*line) && !(*line == '-'))
			return (-1);
		line++;
	}
	return (nb);
}

int		*parse_line(t_env *env, char *line)
{
	int		*tab;
	int		i;
	int		f;

	f = 0;
	i = 0;
	if ((tab = (int*)malloc(sizeof(int) * (nb_words(line) + 1))))
	{
		while (*line)
		{
			if ((ft_isdigit(*line) || *line == '-') && !f)
			{
				f = 1;
				tab[i++] = ft_atoi(line);
			}
			else if (*line == ' ')
				f = 0;
			else if (!ft_isdigit(*line) && !(*line == '-'))
				return (NULL);
			line++;
		}
		env->mapx = i;
		tab[i] = -1;
	}
	return (tab);
}

int		**parse_map(t_env *env, char *mapfile)
{
	char	*line;
	int		**map;
	int		fd;
	int		i;

	if ((map = (int**)malloc(sizeof(int*) * (nbline(mapfile) + 1))))
	{
		i = 0;
		if ((fd = open(mapfile, O_RDONLY)) > 0)
		{
			while (get_next_line(fd, &line) > 0)
			{
				if (!(map[i] = parse_line(env, line)))
					return (NULL);
				i++;
			}
			env->mapy = i;
			close(fd);
			map[i] = NULL;
		}
		else
			return (NULL);
	}
	return (map);
}
