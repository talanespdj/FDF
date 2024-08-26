/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:51:39 by tespandj          #+#    #+#             */
/*   Updated: 2024/05/14 19:27:22 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "mlx/mlx.h"

void	setpixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if ((x < fdf->width && x > 0) && (y < fdf->height && y > 0))
	{
		dst = fdf->data->addr + (y * fdf->data->line_length + x
				* (fdf->data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	freematrix(struct var *map)
{
	int	i;
	int	d;

	i = 0;
	while (map->matrix[i])
	{
		d = 0;
		while (map->matrix[i][d])
		{
			free(map->matrix[i][d]);
			d++;
		}
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
}

void	wegotasituation(struct var *map)
{
	freematrix(map);
	exit(1);
}
