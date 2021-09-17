/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:00:22 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/09/14 21:02:44 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_img
{
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
	void	*img_ptr;
}				t_img;

typedef struct s_fractol
{
	int		res_width;
	int		res_height;
	void	*win_ptr;
	void	*mlx_ptr;
	int		color;
	int		fractal;
	int		x;
	double	x1;
	double	x2;
	int		y;
	double	y1;
	double	y2;
	double	zoom_x;
	double	zoom_y;
	int		img_x;
	int		img_y;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	int		iter_max;
	double	i;
	double	temp;
	float	shift;
	t_img	*img;
}				t_fractol;

int				ft_strcmp(const char *s1, const char *s2);
void			errors(void);
int				fractol(t_fractol *ptr);
int				img_to_win(t_fractol *ptr);
void			init_mandelbrot(t_fractol *ptr, int mode);
void			init_julia(t_fractol *ptr, int mode);
void			init_burningship(t_fractol *ptr, int mode);
int				init_fract(t_fractol *ptr, char **argv, int argc);
int				init(t_fractol *ptr);
void			draw(int x, int y, int color, t_fractol *ptr);
void			launch_burningship(t_fractol *ptr);
void			launch_fractal(t_fractol *ptr);
void			launch_julia(t_fractol *ptr);
void			launch_mandelbrot(t_fractol *ptr);
int				ft_isdigit(int c);
double			ft_atof(char *s);
void    		ft_memset(void *b, int c, size_t len);
void    		ft_calloc(size_t count, size_t size);

#		endif
