/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:01:16 by varichar          #+#    #+#             */
/*   Updated: 2017/03/13 22:23:19 by varichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_coord *start, t_coord *end, t_coord rot)
{
	rotationx(start, rot.x);
	rotationx(end, rot.x);
	rotationy(start, rot.y);
	rotationy(end, rot.y);
	rotationz(start, rot.z);
	rotationz(end, rot.z);
}

void	rotationz(t_coord *coords, int a)
{
	int x;
	int y;
	int z;

	x = coords->x;
	y = coords->y;
	z = coords->z;
	coords->x = x * cos(a) - y * sin(a);
	coords->y = x * sin(a) + y * cos(a);
	coords->z = z;
}

void	rotationy(t_coord *coords, int a)
{
	int x;
	int y;
	int z;

	x = coords->x;
	y = coords->y;
	z = coords->z;
	coords->x = x * cos(a) + z * sin(a);
	coords->y = y;
	coords->z = -(x * sin(a)) + z * cos(a);
}

void	rotationx(t_coord *coords, int a)
{
	int x;
	int y;
	int z;

	x = coords->x;
	y = coords->y;
	z = coords->z;
	coords->x = x;
	coords->y = y * cos(a) - z * sin(a);
	coords->z = y * sin(a) + z * cos(a);
}
