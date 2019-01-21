/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:49:08 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/17 13:49:09 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		key1(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 3 ||
	my->fractal == 4 || my->fractal == 7 || my->fractal == 8)
	{
		if (my->zoom > 1500)
			my->x_move -= 0.001;
		else if (my->zoom > 30000)
			my->x_move -= 0.00001;
		else if (my->zoom > 350000)
			my->x_move -= 0.000000001;
		else if (my->zoom > 100000000)
			my->x_move -= 0.000000000000001;
		else
			my->x_move -= 0.02;
	}
	else if (my->fractal == 5)
	{
		my->serpinsky.scnd_x += 3;
		my->serpinsky.frst_x += 3;
		my->serpinsky.thrd_x += 3;
	}
	else if (my->fractal == 6)
		my->x_move -= 10;
}

void		key3(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 3 ||
	my->fractal == 4 || my->fractal == 7 || my->fractal == 8)
	{
		if (my->zoom > 1500)
			my->x_move += 0.001;
		else if (my->zoom > 30000)
			my->x_move += 0.0001;
		else if (my->zoom > 30000)
			my->x_move += 0.00001;
		else if (my->zoom > 350000)
			my->x_move += 0.000000001;
		else if (my->zoom > 100000000)
			my->x_move += 0.00000000000000001;
		else
			my->x_move += 0.02;
	}
	else if (my->fractal == 5)
	{
		my->serpinsky.scnd_x -= 3;
		my->serpinsky.frst_x -= 3;
		my->serpinsky.thrd_x -= 3;
	}
	else if (my->fractal == 6)
		my->x_move += 10;
}

void		key2(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 3 ||
	my->fractal == 4 || my->fractal == 7 || my->fractal == 8)
	{
		if (my->zoom > 1200 && my->zoom < 2200)
			my->maxiterations += 2;
		else if (my->zoom > 4000 && my->zoom < 8000)
			my->maxiterations += 1;
		else if (my->zoom > 18000 && my->zoom < 30000)
			my->maxiterations += 1;
		else if (my->zoom > 50000 && my->zoom < 100000)
			my->maxiterations += 1;
		else if (my->zoom > 250000 && my->zoom < 1000000)
			my->maxiterations += 1;
		else if (my->zoom > 2000000 && my->zoom < 30000000)
			my->maxiterations += 1;
		else if (my->zoom > 50000000)
			my->maxiterations += 1;
		my->zoom *= 1.1;
	}
	else if (my->fractal == 5)
		zoom_serpi(my);
	else if (my->fractal == 6)
		my->zoom += 0.01;
}

void		key4(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 3 ||
	my->fractal == 4 || my->fractal == 7 || my->fractal == 8)
	{
		if (my->zoom > 1500)
			my->y_move += 0.001;
		else if (my->zoom > 30000)
			my->y_move += 0.00001;
		else if (my->zoom > 350000)
			my->y_move += 0.000000001;
		else if (my->zoom > 100000000)
			my->y_move += 0.0000000000000001;
		else
			my->y_move += 0.02;
	}
	else if (my->fractal == 5)
	{
		my->serpinsky.scnd_y += 3;
		my->serpinsky.frst_y += 3;
		my->serpinsky.thrd_y += 3;
	}
	else if (my->fractal == 6)
		my->y_move -= 10;
}

int			deal_key(int key, t_glob *my)
{
	if (key == 0X35)
		exit(1);
	if (key == 0X7C)
		key1(my);
	if (key == 0X7B)
		key3(my);
	if (key == 0X7E)
		key4(my);
	if (key == 0X7D)
		key5(my);
	if (key == 0X45)
		key2(my);
	if (key == 78)
		my_zom(my);
	pereklucatel(my, key);
	pereklucatel2(my, key);
	pereklucatel3(my, key);
	color_fractol(key, my);
	drav_fractol(my);
	return (0);
}
