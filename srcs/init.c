/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:42:09 by varichar          #+#    #+#             */
/*   Updated: 2017/03/30 13:51:56 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_hooks(t_env *env)
{
	mlx_key_hook(env->win, keyhook, env);
}

void	print_hints(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 25, 40, 0x00CC0000, "y | h :	Hauteur");
	mlx_string_put(env->mlx, env->win, 25, 60, 0x00CC0000, "u | j :	rotation en x");
	mlx_string_put(env->mlx, env->win, 25, 80, 0x00CC0000, "i | k :	rotation en y");
	mlx_string_put(env->mlx, env->win, 25, 100, 0x00CC0000, "o | l :	rotation en z");
	mlx_string_put(env->mlx, env->win, 25, 120, 0x00CC0000, "- | = :	zoom");
	mlx_string_put(env->mlx, env->win, 25, 140, 0x00CC0000, "fleches :	translations");
	mlx_string_put(env->mlx, env->win, 25, 160, 0x00CC0000, "r :	reset");
}

void	init_env(t_env *env, char *map)
{
	env->sizex = WIN_X;
	env->sizey = WIN_Y;
	env->mlx = mlx_init();
	env->scale = 20;
	env->win = mlx_new_window(env->mlx, env->sizex, env->sizey, map);
	env->posx = (env->sizex / env->mapx) * 4;
	env->posy = (env->sizey / env->mapy) * 4;
	env->height = 1;
	env->rot.x = 0;
	env->rot.y = 0;
	env->rot.z = 0;
}
