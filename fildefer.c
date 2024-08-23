/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildefer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:24:52 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/21 22:57:27 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fildefer(struct fdf *fdf, char *argv)
{
	verif_map_name(argv);
	everinit(fdf, argv);
	fillmatrix(fdf);
	verif_map(fdf);
	fill_win(fdf);
}

int	main(int argc, char **argv)
{
	struct fdf	fdf;
	int			fd;

	fd = 0;
	if (argc != 2)
		wgas("fichier incorrect / fd <= 0");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
			wgas("fichier incorrect / fd <= 0");
		close(fd);
		fildefer(&fdf, argv[1]);
		return (0);
	}
	return (0);
}
