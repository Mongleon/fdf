/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:50:43 by varichar          #+#    #+#             */
/*   Updated: 2017/03/13 22:39:00 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <unistd.h>

void	fdf_usage(const char *name)
{
	ft_printf("usage: %s [file]\n", name);
}

void	int_to_coord(t_coord *coords, int x, int y, int z)
{
	coords->x = x;
	coords->y = y;
	coords->z = z;
}

void 	print_map(t_env *env)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	t_coord	start;
	t_coord	end;
	while (j < env->mapy)
	{
		while (i < env->mapx)
		{
			if (j < env->mapy - 1)
			{
				int_to_coord(&start, env->posx + i * env->scale, env->posy + j * env->scale, env->map[j][i] * (env->scale / env->height));
				int_to_coord(&end, env->posx + i * env->scale, env->posy + (j + 1) * env->scale, env->map[j + 1][i] * (env->scale / env->height));
				rotation(&start, &end, env->rot);
				ft_drawline(env, &start, &end);
			}
			if (i < env->mapx - 1)
			{
				int_to_coord(&start, env->posx + i * env->scale, env->posy + j * env->scale, env->map[j][i] * (env->scale / env->height));
				int_to_coord(&end, env->posx + (i + 1) * env->scale, env->posy + j * env->scale, env->map[j][i + 1] * (env->scale / env->height));
				rotation(&start, &end, env->rot);
				ft_drawline(env, &start, &end);
			}
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window (env->mlx, env->win, env->img, 0, 0);
}

int		fdf(char *map)
{
	t_env	env;

	if ((env.map = parse_map(&env, map)))
	{
		env.sizex = WIN_X;
		env.sizey = WIN_Y;
		env.mlx = mlx_init();
		env.scale = 20;
		env.win = mlx_new_window(env.mlx, env.sizex, env.sizey, map);
		env.img = mlx_new_image(env.mlx, env.sizex, env.sizey);
		env.data = mlx_get_data_addr(env.img, &(env.color), \
				&(env.size), &(env.endian));
		env.posx = (env.sizex / env.mapx) * 4;
		env.posy = (env.sizey / env.mapy) * 4;
		env.height = 1;
		env.rot.x = 0;
		env.rot.y =	0;
		env.rot.z = 0;
		print_map(&env);
		mlx_loop(env.mlx);
	}
	else
		ft_printf("Map error on %s\n", map);
	return (0);
}

int		main(int argc, const char **argv)
{
	if (argc == 2)
		fdf((char*)argv[1]);
	else
	fdf_usage(argv[0]);
	return (0);
}
