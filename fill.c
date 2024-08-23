/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:23:09 by tespandj          #+#    #+#             */
/*   Updated: 2024/05/15 17:48:56 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fill_win(struct fdf *fdf)
{
	set_view(fdf);
	draw_fdf(fdf);
	mlx_key_hook(fdf->data->win, key_press, fdf);
	mlx_hook(fdf->data->win, 17, 0, &end_win, fdf);
	mlx_loop(fdf->data->mlx);
}

void	fillmatrix(t_fdf *fdf)
{
	char	*tmpstr;
	int		i;

	i = 0;
	fdf->map->fd = open(fdf->map->name, O_RDONLY);
	if (fdf->map->fd < 0)
		wgas("oupsi j'arrive pas a ouvrir le fd dans fillmatrix");
	fdf->map->matrix = NULL;
	fdf->map->matrix = malloc(sizeof(char **) * (fdf->map->rows + 1));
	if (!fdf->map->matrix)
		wgas("malloc ***matrix echoue faut free map/data/fdf before exit");
	while (i < fdf->map->rows)
	{
		tmpstr = gnl(fdf->map->fd);
		(fdf->map->matrix)[i] = split(tmpstr, ' ');
		free(tmpstr);
		i++;
	}
	fdf->map->matrix[i] = NULL;
	reset_view(fdf);
	close(fdf->map->fd);
}
