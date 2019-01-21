/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:29:15 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/13 18:29:16 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pxl_to_img(t_glob *my, int x, int y, int color)
{
	color = mlx_get_color_value(my->mlx_ptr, color);
	ft_memcpy(my->addr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
}

int			ft_mandelbrot_help(t_glob *my, int *flag, t_mandel *sv)
{
	unsigned int n;

	n = 0;
	while (n++ < my->maxiterations)
	{
		sv->zr_2 = sv->zr * sv->zr;
		sv->zi_2 = sv->zi * sv->zi;
		if (sv->zr_2 + sv->zi_2 > 1.0E5)
		{
			*flag = 0;
			break ;
		}
		sv->zi = 2 * sv->zr * sv->zi + sv->ci;
		sv->zr = sv->zr_2 - sv->zi_2 + sv->cr;
	}
	return (n);
}

void		ft_find_mandelbrot(t_glob *my, int x, int y, t_mandel *sv)
{
	int flag;
	int n;

	while (x++ < WIDTH / 2)
	{
		sv->cr = (float)x / (my->zoom) + my->x_move - 0.5;
		sv->zr = sv->cr;
		sv->zi = sv->ci;
		flag = 1;
		n = ft_mandelbrot_help(my, &flag, sv);
		if (flag)
		{
			put_pxl_to_img(my, x + WIDTH / 2, y + HEIGHT / 2, 0x000000);
		}
		else
		{
			put_pxl_to_img(my, x + WIDTH / 2, y + HEIGHT / 2, my->color * n);
		}
	}
}

void		ft_mandelbrot_init(t_glob *my, int x, int y, int y_max)
{
	t_mandel sv;

	while (y < y_max)
	{
		sv.ci = y / (my->zoom) + (my->y_move) + 0.1;
		x = (WIDTH / 2) * -1;
		ft_find_mandelbrot(my, x, y, &sv);
		y++;
	}
}
