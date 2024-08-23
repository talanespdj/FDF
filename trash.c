/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:36:25 by tespandj          #+#    #+#             */
/*   Updated: 2024/06/20 20:36:28 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	value_z(struct fdf *fdf, int x, int y)
{
	int	z;

	if (!fdf->map->matrix[y])
		z = 0;
	else
		z = talanatoi(fdf, fdf->map->matrix[y][x]);
	return (z);
}

static int	signs(t_fdf *fdf, char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		fdf->map->fd = 42;
		return (0);
	}
	return (sign);
}

int	talanatoi(t_fdf *fdf, char *str)
{
	long long int	res;
	int				i;

	i = 0;
	res = 0;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	res *= signs(fdf, str);
	if (res > 2147483647 || res < -2147483648)
	{
		fdf->map->fd = 42;
		return (0);
	}
	return (res);
}

void	freend(struct fdf *fdf)
{
	freematrix(fdf->map);
	free(fdf->map);
	free(fdf->data);
	free(fdf->cam);
}

void	free_buffer(int fd, char **line)
{
	while (*line)
	{
		free(*line);
		*line = gnl(fd);
	}
}
