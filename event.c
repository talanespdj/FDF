/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:10:58 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/15 15:11:07 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	key_press(int key, struct fdf *fdf)
{
	wasd(key, fdf);
	zra(key, fdf);
	if (key == XK_i)
	{
		fdf->cam->views = ISO;
		fdf->cam->angle = 0.523599;
	}
	if (key == XK_o)
		fdf->cam->views = twoD;
	if (key == XK_j)
		reset_view(fdf);
	if (key == XK_Escape)
		end_win(fdf);
	draw_fdf(fdf);
	return (0);
}

void	wasd(int key, t_fdf *fdf)
{
	if (key == XK_w || key == XK_Up)
		fdf->cam->y_offset -= 20;
	if (key == XK_s || key == XK_Down)
		fdf->cam->y_offset += 20;
	if (key == XK_d || key == XK_Right)
		fdf->cam->x_offset += 20;
	if (key == XK_a || key == XK_Left)
		fdf->cam->x_offset -= 20;
	if (key == XK_Page_Down)
		fdf->cam->x_offset += 60;
	if (key == XK_Delete)
		fdf->cam->x_offset -= 60;
	if (key == XK_End)
		fdf->cam->y_offset += 60;
	if (key == XK_Home)
		fdf->cam->y_offset -= 60;
}

void	zra(int key, t_fdf *fdf)
{
	if (key == XK_q || key == XK_Page_Up)
	{
		if (fdf->cam->zoom <= 30)
			fdf->cam->zoom += 1;
	}
	if (key == XK_e || key == XK_Insert)
	{
		if (fdf->cam->zoom >= 1)
			fdf->cam->zoom -= 1;
	}
	if (key == XK_k || key == XK_KP_End)
		fdf->cam->relief += 1;
	if (key == XK_h || key == XK_KP_Page_Down)
		fdf->cam->relief -= 1;
	if (key == XK_y)
		fdf->cam->angle += 0.05;
	if (key == XK_u)
		fdf->cam->angle -= 0.05;
}
