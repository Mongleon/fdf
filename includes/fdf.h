/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:26:19 by varichar          #+#    #+#             */
/*   Updated: 2017/01/27 16:48:25 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			**map;
}				t_env;

int		**parse_map(char *mapfile);

#endif