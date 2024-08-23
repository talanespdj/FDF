/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:03:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/16 16:03:35 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "mlx/mlx.h"

void	everinit(struct fdf *fdf, char *argv)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (fdf->map == NULL)
		exit(EXIT_FAILURE);
	fdf->map->name = argv;
	fdf->map->rows = nb_rows(fdf);
	fdf->map->columns = nb_columns(fdf->map);
	fdf->data = (t_mlx *)malloc(sizeof(t_mlx));
	if (fdf->data == NULL)
	{
		free(fdf->map);
		exit(EXIT_FAILURE);
	}
	fdf->cam = (t_cam *)malloc(sizeof(t_cam));
	if (fdf->cam == NULL)
	{
		free(fdf->map);
		free(fdf->data);
		exit(EXIT_FAILURE);
	}
	lastinit(fdf);
}

void	lastinit(struct fdf *fdf)
{
	fdf->data->mlx = mlx_init();
	if (!fdf->data->mlx)
	{
		free(fdf->map);
		free(fdf->cam);
		free(fdf->data);
		exit(1);
	}
	fdf->width = 0;
	fdf->height = 0;
	mlx_get_screen_size(fdf->data->mlx, &fdf->width, &fdf->height);
	fdf->data->win = mlx_new_window(fdf->data->mlx,
			fdf->width, fdf->height, "FDF MLF");
	if (!fdf->data->win)
	{
		free(fdf->map);
		free(fdf->cam);
		free(fdf->data);
		free(fdf->data->mlx);
		exit(2);
	}
	fdf->data->img = mlx_new_image(fdf->data->mlx, fdf->width, fdf->height);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img,
			&fdf->data->bits_per_pixel,
			&fdf->data->line_length, &fdf->data->endian);
}

int	end_win(struct fdf *fdf)
{
	mlx_destroy_image(fdf->data->mlx, fdf->data->img);
	mlx_destroy_window(fdf->data->mlx, fdf->data->win);
	mlx_destroy_display(fdf->data->mlx);
	free(fdf->data->mlx);
	freend(fdf);
	exit(0);
}

void	reset_view(struct fdf *fdf)
{
	fdf->cam->angle = 0.523599;
	fdf->cam->zoom = 20;
	fdf->cam->relief = 1;
	fdf->cam->x_offset = 0;
	fdf->cam->y_offset = 0;
}

void	set_view(t_fdf *fdf)
{
	t_point		pt;
	int			tmp;

	fdf->cam->angle = 0.523599;
	fdf->cam->zoom = 20;
	fdf->cam->relief = 1;
	fdf->cam->views = ISO;
	pt.x = fdf->map->columns / 2 * fdf->cam->zoom;
	pt.y = fdf->map->rows / 2 * fdf->cam->zoom;
	pt.z = value_z(fdf, fdf->map->columns / 2, fdf->map->rows / 2);
	tmp = pt.x;
	pt.x = (tmp - pt.y) * (cos(fdf->cam->angle));
	pt.y = (tmp + pt.y) * (sin(fdf->cam->angle)) - pt.z;
	if (pt.x < fdf->width / 2)
		fdf->cam->isoffset.x = fdf->width / 2 - pt.x;
	else
		fdf->cam->isoffset.x = -pt.x;
	if (pt.y < fdf->height / 2)
		fdf->cam->isoffset.y = fdf->height / 2 - pt.y;
	else
		fdf->cam->isoffset.y = -pt.y;
}
