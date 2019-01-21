/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:09:48 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/18 13:09:50 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		values_mandelbrot(t_glob *my)
{
	my->maxiterations = 25;
	my->zoom = 200;
	my->x_move = 0;
	my->y_move = 0;
	my->color = 0x010602;
}

void		values_my1(t_glob *my)
{
	my->maxiterations = 25;
	my->zoom = 200;
	my->x_move = 0.45;
	my->y_move = 0;
	my->color = 265;
}

void		values_my2(t_glob *my)
{
	my->maxiterations = 25;
	my->zoom = 200;
	my->x_move = 0.45;
	my->y_move = 0;
	my->color = 265;
}

void		values_my3(t_glob *my)
{
	my->maxiterations = 25;
	my->zoom = 200;
	my->x_move = 0.4;
	my->y_move = 0;
	my->color = 265;
}

void		values_julia(t_glob *my)
{
	my->maxiterations = 200;
	my->zoom = 0.5;
	my->x_move = 0;
	my->y_move = 0;
	my->color = 0x010602;
	my->stop_julia = 1;
	my->re = -0.8169;
	my->im = -0.1189;
}
