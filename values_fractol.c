/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:53:21 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/16 12:53:23 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	chec_value2(t_glob *my)
{
	if (my->fractal == 4)
	{
		values_my1(my);
		drav_fractol(my);
	}
	else if (my->fractal == 5)
	{
		values_serpinsky(my);
		drav_fractol(my);
	}
	else if (my->fractal == 6)
	{
		values_barnsley(my);
		drav_fractol(my);
	}
	else if (my->fractal == 7)
	{
		values_my2(my);
		drav_fractol(my);
	}
	else if (my->fractal == 8)
	{
		values_my3(my);
		drav_fractol(my);
	}
}

void	chec_value(t_glob *my)
{
	if (my->fractal == 1)
	{
		values_mandelbrot(my);
		drav_fractol(my);
	}
	else if (my->fractal == 2)
	{
		values_julia(my);
		drav_fractol(my);
	}
	else if (my->fractal == 3)
	{
		values_burningship(my);
		drav_fractol(my);
	}
	chec_value2(my);
}
