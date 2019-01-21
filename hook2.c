/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:07:49 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/21 18:07:50 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_serpinskogo(t_glob *my, int mousecode)
{
	if (mousecode == 4 || mousecode == 1)
		my->zoom += 0.01;
	if (mousecode == 5 || mousecode == 2)
	{
		my->zoom -= 0.01;
		if (my->zoom < 0.001)
			my->zoom = 0.001;
	}
}

void		ft_stop_julia(t_glob *my)
{
	if (my->stop_julia == 1)
		my->stop_julia = 0;
	else
		my->stop_julia = 1;
	drav_fractol(my);
}

void		ft_my_restart(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2)
		ft_restart(my);
	else if (my->fractal == 5)
		ft_restart2(my);
	else if (my->fractal == 3)
		restart3(my);
	else if (my->fractal == 4)
		restart4(my);
	else if (my->fractal == 6)
		restart5(my);
	else if (my->fractal == 7)
		restart6(my);
	else if (my->fractal == 8)
		restart7(my);
}

void		my_zom(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 4 ||
		my->fractal == 7 || my->fractal == 8)
	{
		if (my->maxiterations > 25)
			my->maxiterations -= 1;
		my->zoom /= 1.1;
	}
	else if (my->fractal == 5)
		zoom_serpi_up(my);
	else if (my->fractal == 3)
		my->zoom /= 1.1;
	else if (my->fractal == 6)
	{
		my->zoom -= 0.01;
		if (my->zoom < 0.001)
			my->zoom = 0.001;
	}
}

void		pereklucatel(t_glob *my, int key)
{
	if (key == 18)
	{
		values_mandelbrot(my);
		my->fractal = 1;
	}
	if (key == 19)
	{
		values_julia(my);
		my->fractal = 2;
	}
	if (key == 20)
	{
		values_burningship(my);
		my->fractal = 3;
	}
	if (key == 23)
	{
		values_serpinsky(my);
		my->fractal = 5;
	}
}
