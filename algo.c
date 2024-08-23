/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <tespandj@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:13:33 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/15 20:12:27 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	draw_fdf(struct fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	reset_fdf(fdf);
	while (++y < fdf->map->rows)
	{
		x = -1;
		while (++x < fdf->map->columns)
		{
			if (fdf->map->matrix[y][x + 1])
				breseline(fdf, np(fdf, x, y), np(fdf, x + 1, y));
			if (fdf->map->matrix[y + 1])
				breseline(fdf, np(fdf, x, y), np(fdf, x, y + 1));
		}
	}
	mlx_put_image_to_window(fdf->data->mlx,
		fdf->data->win, fdf->data->img, 0, 0);
}

t_point	np(struct fdf *fdf, int x, int y)
{
	t_point	pt;

	pt.x = x * fdf->cam->zoom;
	pt.y = y * fdf->cam->zoom;
	pt.z = value_z(fdf, x, y) * fdf->cam->relief;
	projection(fdf, &pt);
	return (pt);
}

void	projection(t_fdf *fdf, t_point *pt)
{	
	int	tmp;

	if (fdf->cam->views == twoD)
	{
		pt->x += fdf->width / 2 - (fdf->map->columns / 2) * fdf->cam->zoom;
		pt->y += fdf->height / 2 - (fdf->map->rows / 2) * fdf->cam->zoom;
	}
	else if (fdf->cam->views == ISO)
	{
		tmp = pt->x;
		pt->x = (tmp - pt->y) * (cos(fdf->cam->angle));
		pt->y = (tmp + pt->y) * (sin(fdf->cam->angle)) - pt->z;
		pt->x += fdf->cam->isoffset.x;
		pt->y += fdf->cam->isoffset.y;
	}
	pt->x += fdf->cam->x_offset;
	pt->y += fdf->cam->y_offset;
}

void	reset_fdf(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= fdf->height)
	{
		x = -1;
		while (++x <= fdf->width)
			setpixel(fdf, x, y, 0);
	}
}
