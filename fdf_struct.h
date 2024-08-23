/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:11:16 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/19 23:11:20 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H
# include "fdf.h"

typedef enum proj
{
	ISO,
	twoD,
	PARALLEL
}		t_proj;

typedef struct point
{
	int	x;
	int	y;
	int	z;
}		t_point;



typedef struct var
{
	char		***matrix;
	char		*name;
	int			columns;
	int			color;
	int			rows;
	int			fd;
}		t_map;

typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}		t_mlx;

typedef struct cam
{
	// t_point		twod_offset;
	t_point		isoffset;
	t_proj		views;
	double		angle;
	int			zoom;
	int			relief;
	int			x_offset;
	int			y_offset;
}		t_cam;

typedef struct spt
{
	const char	*str;
	char		**split;
	char		c;
	int			nb_words;
	int			indic;
	int			len;
	int			op;
	int			i;
}			t_split;

typedef struct s_bsl
{
	int dx;
	int dy;
	int dx1;
	int dy1;
	int px;
	int py;
	int x;
	int y;
	int xe;
	int  ye;;
}	t_bsl;

typedef struct fdf
{
	struct mlx	*data;
	struct var	*map;
	struct cam	*cam;
	int	width;
	int	height;
}		t_fdf;

#endif
