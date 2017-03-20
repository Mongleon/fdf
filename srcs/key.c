/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 08:12:07 by varichar          #+#    #+#             */
/*   Updated: 2017/03/20 13:29:41 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_key(int keycode, t_env *env)
{
	if (keycode == 32)
		env->rot.x += 5;
	if (keycode == 38)
		env->rot.x -= 5;
	if (keycode == 34)
		env->rot.y += 5;
	if (keycode == 40)
		env->rot.y -= 5;
	if (keycode == 31)
		env->rot.z += 5;
	if (keycode == 37)
		env->rot.z -= 5;
	
}

void	trans_key(int keycode, t_env *env)
{
	if (keycode == 126)
		env->posy -= 20;
	if (keycode == 125)
		env->posy += 20;
	if (keycode == 123)
		env->posx -= 20;
	if (keycode == 124)
		env->posx += 20;
}

void	scale_key(int keycode, t_env *env)
{
	if (keycode == 24)
		env->scale += 2;
	if (keycode == 27)
		env->scale -= 2;
}

int		keyhook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == 53)
		end_run(env);
	rot_key(keycode, env);
	trans_key(keycode, env);
	scale_key(keycode, env);
	printf("%d\n", keycode);
	mlx_destroy_image(env->mlx, env->img);
	print_map(env);
	return (0);
}
