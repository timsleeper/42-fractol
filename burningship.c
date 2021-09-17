/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:05:13 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/09/14 20:10:25 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burningship(t_fractol *ptr, int mode)
{
	ptr->i = 0;
	if (mode == 1)
	{
		ptr->x1 = -2.2;
		ptr->x2 = 1.0;
		ptr->y1 = -2.5;
		ptr->y2 = 1.0;
		ptr->zoom_x = 220;
		ptr->zoom_y = 220;
		ptr->c_r = ptr->x / ptr->zoom_x + ptr->x1;
		ptr->c_i = ptr->y / ptr->zoom_y + ptr->y1;
		ptr->z_r = 0;
		ptr->z_i = 0;
		ptr->iter_max = 50;
		ptr->img_x = ptr->res_width;
		ptr->img_y = ptr->res_height;
		ptr->color = 0x10FA66;
	}
	else if (mode == 2)
	{
		ptr->c_r = ptr->x / ptr->zoom_x + ptr->x1;
		ptr->c_i = ptr->y / ptr->zoom_y + ptr->y1;
		ptr->z_r = 0;
		ptr->z_i = 0;
	}
}

void	launch_burningship(t_fractol *ptr)
{
	ptr->x = -1;
	while (++ptr->x < ptr->img_x)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			init_burningship(ptr, 2);
			while (ptr->z_r * ptr->z_r + ptr->z_i * ptr->z_i < 4
				&& ptr->i < ptr->iter_max)
			{
				ptr->temp = ptr->z_r * ptr->z_r - ptr->z_i
					* ptr->z_i + ptr->c_r;
				ptr->z_i = fabs(2 * ptr->z_i * ptr->z_r) + ptr->c_i;
				ptr->z_r = ptr->temp;
				ptr->i++;
			}
			draw(ptr->x, ptr->y, ptr->i * ptr->color / ptr->iter_max, ptr);
			ptr->y++;
		}
	}
}
