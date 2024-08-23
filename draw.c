/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:26:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/21 23:30:42 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	breseline(struct fdf *fdf, t_point a, t_point b)
{
	t_bsl	t;

	bslinit(&t, a, b);
	fdf->map->color = 0xD7263D;
	if (t.dy1 <= t.dx1)
		sbto(fdf, &t);
	else
	{
		if (t.dy >= 0)
		{
			t.x = a.x;
			t.y = a.y;
			t.ye = b.y;
		}
		else
		{
			t.x = b.x;
			t.y = b.y;
			t.ye = a.y;
		}
		setpixel(fdf, t.x, t.y, fdf->map->color);
		slto(fdf, &t);
	}
}

void	bslinit(t_bsl *t, t_point a, t_point b)
{
	t->dx = b.x - a.x;
	t->dy = b.y - a.y;
	t->dx1 = talanabs(t->dx);
	t->dy1 = talanabs(t->dy);
	t->px = 2 * t->dy1 - t->dx1;
	t->py = 2 * t->dx1 - t->dy1;
	if (t->dy1 <= t->dx1)
	{
		if (t->dx >= 0)
		{
			t->x = a.x;
			t->y = a.y;
			t->xe = b.x;
		}
		else
		{
			t->x = b.x;
			t->y = b.y;
			t->xe = a.x;
		}
	}
}

void	slto(struct fdf *fdf, t_bsl *t)
{
	while (t->y < t->ye)
	{
		t->y++;
		if (t->py <= 0)
			t->py = t->py + 2 * t->dx1;
		else
		{
			if ((t->dx < 0 && t->dy < 0) || (t->dx > 0 && t->dy > 0))
				t->x++;
			else
				t->x--;
			t->py = t->py + 2 * (t->dx1 - t->dy1);
		}
		setpixel(fdf, t->x, t->y, fdf->map->color);
	}
}

void	sbto(struct fdf *fdf, t_bsl *t)
{
	setpixel(fdf, t->x, t->y, fdf->map->color);
	while (t->x < t->xe)
	{
		t->x++;
		if (t->px < 0)
			t->px = t->px + 2 * t->dy1;
		else
		{
			if ((t->dx < 0 && t->dy < 0) || (t->dx > 0 && t->dy > 0))
				t->y++;
			else
				t->y--;
			t->px = t->px + 2 * (t->dy1 - t->dx1);
		}
		setpixel(fdf, t->x, t->y, fdf->map->color);
	}
}

int	talanabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
