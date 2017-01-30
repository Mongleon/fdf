/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:26:19 by varichar          #+#    #+#             */
/*   Updated: 2017/01/30 21:13:15 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"


typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_draw;

typedef struct	s_img
{
	void	*img;
	int		x;
	int		y;
}				t_img

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	int			**map;
}				t_env;

int		**parse_map(char *mapfile);
void		ft_drawline(t_env *env, t_coord *start, t_coord *end);

#endif
