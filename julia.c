/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:06:44 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/09/14 20:10:34 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *ptr, int mode)
{
	if (mode == 1)
	{
		ptr->x1 = -2.0;
		ptr->x2 = 2.0;
		ptr->y1 = -2;
		ptr->y2 = 1.9;
		ptr->img_x = ptr->res_width;
		ptr->img_y = ptr->res_height;
		ptr->zoom_x = ptr->img_x / (ptr->x2 - ptr->x1);
		ptr->zoom_y = ptr->img_y / (ptr->y2 - ptr->y1);
		ptr->z_r = 0;
		ptr->z_i = 0;
		ptr->iter_max = 30;
		ptr->color = 0xFA1588;
		ptr->i = 0;
	}
	else if (mode == 2)
	{
		ptr->z_r = ptr->x / ptr->zoom_x + ptr->x1;
		ptr->z_i = ptr->y / ptr->zoom_y + ptr->y1;
		ptr->i = 0;
	}
}

void	launch_julia(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->img_x)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			init_julia(ptr, 2);
			while (ptr->z_r * ptr->z_r + ptr->z_i * ptr->z_i < 4
				&& ptr->i < ptr->iter_max)
			{
				ptr->temp = ptr->z_r;
				ptr->z_r = ptr->z_r * ptr->z_r - ptr->z_i * ptr->z_i + ptr->c_r;
				ptr->z_i = 2 * ptr->z_i * ptr->temp + ptr->c_i;
				ptr->i++;
			}
			draw(ptr->x, ptr->y, ptr->i * ptr->color / ptr->iter_max, ptr);
			ptr->y++;
		}
		ptr->x++;
	}
}
