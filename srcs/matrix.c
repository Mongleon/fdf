/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varichar <varichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 21:01:16 by varichar          #+#    #+#             */
/*   Updated: 2017/03/19 17:43:36 by varichar         ###   ########.fr       */
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
	float an;

	an = a * M_PI / 180;
	x = coords->x * cos(an) - coords->y * sin(an);
	y = coords->x * sin(an) + coords->y * cos(an);
	coords->x = x;
	coords->y = y;
}

void	rotationy(t_coord *coords, int a)
{
	int x;
	int z;
	float an;

	an = a * M_PI / 180;
	x = coords->x * cos(an) + coords->z * sin(an);
	z = -(coords->x * sin(an)) + coords->z * cos(an);
	coords->x = x;
	coords->z = z;
}

void	rotationx(t_coord *coords, int a)
{
	int y;
	int z;
	float an;

	an = a * M_PI / 180;
	y = coords->y * cos(an) - coords->z * sin(an);
	z = coords->y * sin(an) + coords->z * cos(an);
	coords->y = y;
	coords->z = z;
}
