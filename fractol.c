/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:05:31 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/09/13 22:56:08 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_function(int keycode, int x, int y, t_fractol *ptr)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = x / ptr->zoom_x + ptr->x1;
	tmp_y = y / ptr->zoom_y + ptr->y1;
	if (keycode == 5)
	{
		ptr->zoom_x /= 1.1;
		ptr->zoom_y /= 1.1;
		ptr->shift *= 1.1;
	}
	if (keycode == 4)
	{
		ptr->zoom_x *= 1.1;
		ptr->zoom_y *= 1.1;
		ptr->shift /= 1.1;
	}
	ptr->x1 = tmp_x - (x / ptr->zoom_x);
	ptr->y1 = tmp_y - (y / ptr->zoom_y);
	img_to_win(ptr);
	return (0);
}

int	key_function(int keycode, t_fractol *ptr)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
		mlx_destroy_display(ptr->mlx_ptr);
		free(ptr->img);
		free(ptr->mlx_ptr);
		free(ptr);
		exit(0);
	}
	if (keycode == 115)
	{
		ptr->color = ptr->color + 0xf00000;
	}	
	if (keycode == 65361)
		ptr->x1 -= ptr->shift;
	if (keycode == 65363)
		ptr->x1 += ptr->shift;
	if (keycode == 65362)
		ptr->y1 -= ptr->shift;
	if (keycode == 65364)
		ptr->y1 += ptr->shift;
	img_to_win(ptr);
	return (0);
}

void	init_ptr(t_fractol *ptr)
{
	if (ptr->fractal == 1)
		init_mandelbrot(ptr, 1);
	else if (ptr->fractal == 2)
		init_julia(ptr, 1);
	else if (ptr->fractal == 3)
		init_burningship(ptr, 1);
}

int	init_fract(t_fractol *ptr, char **argv, int argc)
{
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		ptr->fractal = 1;
	else if (ft_strcmp("julia", argv[1]) == 0 && argc == 4)
	{
		ptr->fractal = 2;
		ptr->c_r = ft_atof(argv[2]);
		ptr->c_i = ft_atof(argv[3]);
	}
	else if (ft_strcmp("burningship", argv[1]) == 0)
		ptr->fractal = 3;
	else
		return (0);
	init_ptr(ptr);
	return (1);
}

int	fractol(t_fractol *ptr)
{
	init(ptr);
	mlx_hook(ptr->win_ptr, 2, 1L << 0, key_function, ptr);
	mlx_mouse_hook(ptr->win_ptr, zoom_function, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
