/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_my.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:53:59 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/19 14:54:00 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mandelbrot_help1(t_glob *my, int *flag, t_mandel *sv)
{
	unsigned int n;

	n = 0;
	while (n++ < my->maxiterations)
	{
		sv->zr_2 = (sv->zr * sv->zr);
		sv->zi_2 = (sv->zi * sv->zi);
		if (sv->zr_2 + sv->zi_2 > 1.0E5)
		{
			*flag = 0;
			break ;
		}
		sv->tmp = (pow(sv->zr, 5)) - (10 * (pow(sv->zr, 3)) *
				(sv->zi * sv->zi)) + (5 * sv->zr * (pow(sv->zi, 4))) + sv->cr;
		sv->zi = (5 * (pow(sv->zr, 4)) * sv->zi) - (10 * (sv->zr * sv->zr) *
				(pow(sv->zi, 3))) + (pow(sv->zi, 5)) + sv->ci;
		sv->zr = sv->tmp;
	}
	return (n);
}

void		ft_find_mandelbrot1(t_glob *my, int x, int y, t_mandel *sv)
{
	int flag;
	int n;

	while (x++ < WIDTH / 2)
	{
		sv->cr = (float)x / (my->zoom) + my->x_move - 0.5;
		sv->zr = sv->cr;
		sv->zi = sv->ci;
		flag = 1;
		n = ft_mandelbrot_help1(my, &flag, sv);
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

void		ft_my_mand(t_glob *my, int x, int y, int y_max)
{
	t_mandel	sv;

	while (y < y_max)
	{
		sv.ci = y / (my->zoom) + (my->y_move) + 0.1;
		x = (WIDTH / 2) * -1;
		ft_find_mandelbrot1(my, x, y, &sv);
		y++;
	}
}
