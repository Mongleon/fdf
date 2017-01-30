/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:27:07 by varichar          #+#    #+#             */
/*   Updated: 2017/01/30 21:06:03 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	ft_drawline(t_env *env, t_coord *start, t_coord *end)
{
	t_draw	*d;

	d = malloc(sizeof(t_draw));
	d->dx = ft_abs(end->x - start->x);
	d->sx = (start->x < end->x) ? 1 : -1;
	d->dy = ft_abs(end->y - start->y);
	d->sy = (start->y < end->y) ? 1 : -1; 
	d->err = ((d->dx > d->dy) ? d->dx : -d->dy) / 2;
	mlx_pixel_put(env->mlx, env->win, start->x, start->y, 16581375);
	while (start->x != end->x && start->y != end->y)
	{
		d->e2 = d->err;
		if (d->e2 > -d->dx)
		{
			d->err -= d->dy;
			start->x += d->sx;
		}
		if (d->e2 < d->dy)
		{
			d->err += d->dx;
			start->y += d->sy;
		}
		mlx_pixel_put(env->mlx, env->win, start->x, start->y, 16581375);
	}
}
