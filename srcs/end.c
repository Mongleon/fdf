/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 08:49:48 by varichar          #+#    #+#             */
/*   Updated: 2017/03/20 20:53:02 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_env(t_env *env)
{
	free(env->map);
	free(env->data);
}

void	end_run(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	free_env(env);
	exit(0);
}
