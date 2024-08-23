/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:33:03 by tespandj          #+#    #+#             */
/*   Updated: 2024/08/21 23:29:52 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "fdf_struct.h"
# include <X11/X.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void			fildefer(struct fdf *fdf, char *argv);

void			everinit(struct fdf *fdf, char *argv);
void			lastinit(struct fdf *fdf);
int			end_win(struct fdf *fdf);
void			reset_view(struct fdf *fdf);
void			set_view(t_fdf *fdf);

void            	setpixel(t_fdf *fdf, int x, int y, int color);
void			freematrix(struct var *map);
void			affmatrix(struct var *map);
void			wegotasituation(struct var *map);

char			*gnl(int fd);
int				trouve(const char *str);
char			*add_str(char *s1, char *s2);
char			*save_static(char *str, int rv);
char			*org(char *str);

//void			breseline(struct fdf *fdf, t_point a, t_point b);

void			fill_win(struct fdf *fdf);
void                   	fillmatrix(t_fdf *fdf);

int				value_z(struct fdf *fdf, int x, int y);
int                     	talanatoi(t_fdf *fdf, char *str);
void			freend(struct fdf *fdf);
void			free_buffer(int fd, char **line);

void			draw_fdf(struct fdf *fdf);
void			projection(t_fdf *fdf, t_point *pt);
void			reset_fdf(t_fdf *fdf);
t_point			np(struct fdf *fdf, int x, int y);

int				key_press(int key, struct fdf *fdf);
void			wasd(int key, t_fdf *fdf);
void                    zra(int key, t_fdf *fdf);


void			verif_map_name(char *str);
int				nb_columns(struct var *map);
int				nb_rows(struct fdf *fdf);
int		        arg_by_l(char *line);

char			**split(char const *str, char c);

void			wgas(char *str);
void	                wegotasplituation(struct spt x);


void	                verif_map(t_fdf *fdf);


void			breseline(struct fdf *fdf, t_point a, t_point b);
void			bslinit(t_bsl *t, t_point a, t_point b);
void			sbto(struct fdf *fdf, t_bsl *t);
void			slto(struct fdf *fdf, t_bsl *t);
int			talanabs(int n);

#endif
