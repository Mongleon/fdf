/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:50:43 by varichar          #+#    #+#             */
/*   Updated: 2017/01/28 18:24:25 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

void	fdf_usage(const char *name)
{
	ft_printf("usage: %s [file]\n", name);
}

int		fdf(char *map)
{
	t_env	*env;

	if ((env = malloc(sizeof(t_env))))
	{
		//env->mlx = mlx_init();
		//env->win = mlx_new_window(env->mlx, 400, 400, "test fdf");
		env->map = parse_map(map);
		while (*(env->map))
		{
			while (*(*(env->map) + 1) > -1)
			{
				ft_printf("%-2d", **(env->map));
				*(env->map) += 1;
			}
			ft_printf("%d\n", **(env->map));
			env->map++;
		}
//		mlx_loop(env);
	}
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
