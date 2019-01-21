/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 09:27:29 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/18 09:27:31 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_serpi(t_glob *my)
{
	if (if_positiv(my) == 1)
	{
		my->maxiterations += 100;
		my->serpinsky.frst_x -= 100;
		my->serpinsky.frst_y += 100;
		my->serpinsky.scnd_y -= 100;
		my->serpinsky.thrd_x += 100;
		my->serpinsky.thrd_y += 100;
	}
}

void		ft_restart(t_glob *my)
{
	if (my->fractal == 1)
	{
		my->maxiterations = 25;
		my->zoom = 200;
		my->x_move = 0;
		my->y_move = 0;
		my->color = 0x010602;
	}
	if (my->fractal == 2)
	{
		my->maxiterations = 200;
		my->zoom = 0.5;
		my->x_move = 0;
		my->y_move = 0;
		my->color = 0x010602;
		my->mousere = 0;
		my->mouseim = 0;
		my->stop_julia = 1;
		my->re = -0.8169;
		my->im = -0.1189;
	}
}

void		color_fractol(int key, t_glob *my)
{
	if (key == 83)
		my->color = 0X0359DB;
	if (key == 84)
		my->color = 0X6E092A;
	if (key == 85)
		my->color = 0X0AAEF0;
	if (key == 86)
		my->color = 0X06E7F3;
	if (key == 87)
		my->color = 0X00F88B;
	if (key == 88)
		my->color = 0X0CFB4B;
	if (key == 89)
		my->color = 0X0BFE38;
	if (key == 91)
		my->color = 0X990314;
	if (key == 92)
		my->color = 0XD0D0D0;
}

void		key5(t_glob *my)
{
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 3
	|| my->fractal == 4 || my->fractal == 7 || my->fractal == 8)
	{
		if (my->zoom > 1500)
			my->y_move -= 0.001;
		else if (my->zoom > 30000)
			my->y_move -= 0.00001;
		else if (my->zoom > 350000)
			my->y_move -= 0.0000000001;
		else if (my->zoom > 10000000)
			my->y_move -= 0.0000000000000001;
		else
			my->y_move -= 0.02;
	}
	else if (my->fractal == 5)
	{
		my->serpinsky.scnd_y -= 3;
		my->serpinsky.frst_y -= 3;
		my->serpinsky.thrd_y -= 3;
	}
	else if (my->fractal == 6)
		my->y_move += 10;
}

int			mouse_hook(int mousecode, int x, int y, t_glob *my)
{
	x = 0;
	y = 0;
	if (my->fractal == 1 || my->fractal == 2 || my->fractal == 3 ||
	my->fractal == 4 || my->fractal == 7 || my->fractal == 8)
	{
		if (mousecode == 4 || mousecode == 1)
			my->zoom *= 1.1;
		else if (mousecode == 5 || mousecode == 2)
			my->zoom /= 1.1;
	}
	if (my->fractal == 5)
	{
		if (mousecode == 4 || mousecode == 1)
			zoom_serpi_up(my);
		else if (mousecode == 5 || mousecode == 2)
		{
			zoom_serpi(my);
		}
	}
	if (my->fractal == 6)
		zoom_serpinskogo(my, mousecode);
	drav_fractol(my);
	ft_string_put(my);
	return (0);
}
