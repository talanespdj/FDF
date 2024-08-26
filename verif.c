/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:23:17 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/16 20:26:43 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	verif_map_name(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		exit(1);
	if (!(str[i - 1] == 'f' && str[i - 2] == 'd' && str[i - 3]
			== 'f' && str[i - 4] == '.'))
		exit(1);
}

int	nb_columns(struct var *map)
{
	char	*line;
	int		nb;

	map->fd = open(map->name, O_RDONLY);
	line = gnl(map->fd);
	nb = arg_by_l(line);
	while (line)
	{
		if (arg_by_l(line) != nb)
		{
			free_buffer(map->fd, &line);
			close(map->fd);
			free(map);
			wgas("invalid map // not the same amount of args by rows");
		}
		free(line);
		line = gnl(map->fd);
	}
	close(map->fd);
	if (nb <= 1)
		wgas("invalid map // only one column\n");
	return (nb);
}

int	nb_rows(struct fdf *fdf)
{
	char	*line;
	int		i;

	i = 0;
	fdf->map->fd = open(fdf->map->name, O_RDONLY);
	line = gnl(fdf->map->fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = gnl(fdf->map->fd);
	}
	free(line);
	close(fdf->map->fd);
	if (i <= 1)
	{
		free(fdf->map);
		wgas("invalid map // only one line\n");
	}
	return (i);
}

int	arg_by_l(char *line)
{
	char	**str;
	int		i;

	i = 0;
	str = split(line, ' ');
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (i);
}

void	verif_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	fdf->map->fd = 0;
	while (++y < fdf->map->rows)
	{
		x = -1;
		while (++x < fdf->map->columns)
		{
			if (fdf->map->matrix[y][x][0] && fdf->map->matrix[y][x][1])
				talanatoi(fdf, fdf->map->matrix[y][x]);
		}
	}
	if (fdf->map->fd == 42)
		end_win(fdf);
}
