/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:57:11 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/18 12:57:13 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_count_pixel(t_glob *my, int x, int y)
{
	if (y > 0)
		return (y * my->size_line + x * 4);
	else if (y == 0)
		return (my->size_line + x * 4);
	else if (y < 0)
		return (0);
	return (0);
}

void		ft_pixel_color_julia(t_glob *my, int x, int y, int color)
{
	int i;

	i = ft_count_pixel(my, x, y - 1);
	my->addr[i] = color * 2;
	my->addr[i + 1] = color % 10 * 3;
	my->addr[i + 2] = color - 7;
}

void		ft_julia_help(t_glob *my, int x, int y, int y_max)
{
	t_julia				sv;
	int					y1;
	unsigned int		i;

	y1 = y;
	y = y1 + HEIGHT / 2;
	while (y++ < y_max + HEIGHT / 2)
	{
		sv.re = 1.5 * (x - WIDTH / 2) / (0.5 * my->zoom * WIDTH)
				+ my->x_move + my->mousere;
		sv.im = (y - HEIGHT / 2) / (0.5 * my->zoom * HEIGHT)
				+ my->y_move + my->mouseim;
		i = 0;
		while (i++ < my->maxiterations)
		{
			sv.re_old = sv.re;
			sv.im_old = sv.im;
			sv.re = sv.re_old * sv.re_old - sv.im_old * sv.im_old + my->re;
			sv.im = 2 * sv.re_old * sv.im_old + my->im;
			if ((sv.re * sv.re + sv.im * sv.im) > 10E16)
				break ;
		}
		ft_pixel_color_julia(my, x, y, i * my->color);
	}
}

void		ft_julia_init(t_glob *my, int x, int y, int y_max)
{
	while (x++ < WIDTH)
		ft_julia_help(my, x, y, y_max);
}
