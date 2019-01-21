/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:55:40 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/13 16:55:41 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_julia(int x, int y, t_glob *my)
{
	if (my->fractal == 2)
	{
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && my->stop_julia == 1)
		{
			my->re = -0.7469 - (double)x / 2000;
			my->im = -0.1089 - (double)y / 2000;
		}
		drav_fractol(my);
	}
	return (0);
}

int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void		ft_string_put(t_glob *my)
{
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 40, 0x8ff, (char*)Q);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 60, 0x8ff, (char*)W);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 80, 0x8ff, (char*)E);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 100, 0x8ff, (char*)R);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 120, 0x8ff, (char*)T);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 140, 0x8ff, (char*)U);
	mlx_string_put(my->mlx_ptr, my->win_ptr, 25, 160, 0x8ff, (char*)I);
}

void		drav_fractol(t_glob *my)
{
	ft_bzero(my->addr, WIDTH * HEIGHT * 4);
	ft_threads(my);
	mlx_put_image_to_window(my->mlx_ptr, my->win_ptr, my->image, 0, 0);
	ft_string_put(my);
}

void		new_window(t_glob *my)
{
	my->mlx_ptr = mlx_init();
	my->win_ptr = mlx_new_window(my->mlx_ptr, HEIGHT, WIDTH, F);
	my->image = mlx_new_image(my->mlx_ptr, WIDTH, HEIGHT);
	my->addr = mlx_get_data_addr(my->image, &my->bits_per_pixel,
			&my->size_line, &my->endian);
	chec_value(my);
	mlx_hook(my->win_ptr, 6, 1L < 6, mouse_julia, my);
	mlx_hook(my->win_ptr, 2, 5, deal_key, my);
	mlx_hook(my->win_ptr, 17, 1L << 17, exit_x, my);
	mlx_mouse_hook(my->win_ptr, mouse_hook, my);
	ft_string_put(my);
	mlx_loop(my->mlx_ptr);
}
