/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:02:16 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/09/14 20:07:28 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(int x, int y, int color, t_fractol *ptr)
{
	int	index;
	int	*ptr2;

	if (x >= 0 && x < ptr->res_width && y >= 0 && y < ptr->res_height)
	{
		index = y * ptr->img->size_l + x * ptr->img->bpp / 8;
		ptr2 = (int *)&ptr->img->data[index];
		*ptr2 = color;
	}
}

void	launch_fractal(t_fractol *ptr)
{
	if (ptr->fractal == 1)
		launch_mandelbrot(ptr);
	else if (ptr->fractal == 2)
		launch_julia(ptr);
	else if (ptr->fractal == 3)
		launch_burningship(ptr);
}

int	img_to_win(t_fractol *ptr)
{
	if(ptr->img->img_ptr)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	ptr->img->img_ptr = mlx_new_image(ptr->mlx_ptr,
			ptr->res_width, ptr->res_height);
	if (!(ptr->img->img_ptr))
		errors();
	ptr->img->data = mlx_get_data_addr(ptr->img->img_ptr,
			&ptr->img->bpp, &ptr->img->size_l, &ptr->img->endian);
	if (!(ptr->img->data))
		errors();
	launch_fractal(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr,
		ptr->win_ptr, ptr->img->img_ptr, 0, 0);
	return (0);
}

int	init(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!(ptr->mlx_ptr))
		errors();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
			ptr->res_width, ptr->res_height, "Fractol");
	if (!(ptr->win_ptr))
		errors();
	img_to_win(ptr);
	return (0);
}

double	ft_atof(char *s)
{
	double	val;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	val = 0.0;
	power = 1.0;
	i = 0;
	if (s[i++] == '-')
		sign = -1;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * val / power);
}
