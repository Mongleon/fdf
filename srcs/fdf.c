/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:50:43 by varichar          #+#    #+#             */
/*   Updated: 2017/01/29 15:43:20 by varichar         ###   ########.fr       */
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
		if ((env->map = parse_map(map)))
		{
			env->mlx = mlx_init();
			env->win = mlx_new_window(env->mlx, 400, 400, "test fdf");
			mlx_loop(env);
		}
		else
			ft_printf("Map error on %s\n", map);
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
