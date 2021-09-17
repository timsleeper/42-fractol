/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:59:57 by ftadeu-d          #+#    #+#             */
/*   Updated: 2021/09/13 20:37:45 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	errors(void)
{
	printf("error\n");
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

int	main(int argc, char **argv)
{
	t_fractol	*ptr;

	ptr = NULL;

	ptr = (t_fractol *)malloc(sizeof(t_fractol));
	if (!ptr)
		errors();
	ptr->img = (t_img *)malloc(sizeof(t_img));
	if (!ptr->img)
		errors();
	ptr->res_width = 800;
	ptr->res_height = 600;
	ptr->shift = 0.1;
	if (argc < 2 || argc > 4 || init_fract(ptr, argv, argc) != 1)
	{
		printf("./fractol mandelbrot\n./fractol julia x.xxx x.xxx\n");
		printf("./fractol burningship\n");
		exit(0);
	}
	fractol(ptr);
	return (0);
}
