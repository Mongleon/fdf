/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:42:09 by varichar          #+#    #+#             */
/*   Updated: 2017/03/14 11:50:01 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_env *env, char *map)
{
	env->sizex = WIN_X;
	env->sizey = WIN_Y;
	env->mlx = mlx_init();
	env->scale = 20;
	env->win = mlx_new_window(env->mlx, env->sizex, env->sizey, map);
	env->img = mlx_new_image(env->mlx, env->sizex, env->sizey);
	env->data = mlx_get_data_addr(env->img, &(env->color), \
			&(env->size), &(env->endian));
	env->posx = (env->sizex / env->mapx) * 4;
	env->posy = (env->sizey / env->mapy) * 4;
	env->height = 1;
	env->rot.x = 0;
	env->rot.y =	0;
	env->rot.z = 0;
}
