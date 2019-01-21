/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:50:29 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/13 14:50:30 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error1(void)
{
	ft_putendl("error: wrong name fractol");
	ft_putendl("\t   *");
	ft_putendl("\t   *");
	ft_putendl("\t   *");
	ft_putendl("\t   *");
	ft_putendl("    - mandelbrot");
	ft_putendl("    - julia");
	ft_putendl("    - burningship");
	ft_putendl("    - serpinskogo");
	ft_putendl("    - barnsley");
	ft_putendl("    - My1");
	ft_putendl("    - My2");
	ft_putendl("    - My3");
	exit(1);
}

void		error(void)
{
	ft_putendl("usage: not enough arguments");
	exit(1);
}

void		ft_usage(char *str, t_glob *my)
{
	my->fractal = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
		my->fractal = 1;
	else if (ft_strcmp(str, "julia") == 0)
		my->fractal = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		my->fractal = 3;
	else if (ft_strcmp(str, "My1") == 0)
		my->fractal = 4;
	else if (ft_strcmp(str, "serpinskogo") == 0)
		my->fractal = 5;
	else if (ft_strcmp(str, "barnsley") == 0)
		my->fractal = 6;
	else if (ft_strcmp(str, "My2") == 0)
		my->fractal = 7;
	else if (ft_strcmp(str, "My3") == 0)
		my->fractal = 8;
	else if (my->fractal == 0)
		error1();
}

void		ft_restart2(t_glob *my)
{
	my->maxiterations = 5000;
	my->serpinsky.scnd_x = 580;
	my->serpinsky.scnd_y = 50;
	my->serpinsky.frst_x = 80;
	my->serpinsky.frst_y = 1050;
	my->serpinsky.thrd_x = 1080;
	my->serpinsky.thrd_y = 1050;
	my->color = 666;
}

void		restart4(t_glob *my)
{
	my->maxiterations = 25;
	my->zoom = 200;
	my->x_move = 0.45;
	my->y_move = 0;
	my->color = 265;
}
