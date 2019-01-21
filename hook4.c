/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:16:02 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/21 11:16:03 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pereklucatel2(t_glob *my, int key)
{
	if (key == 49)
		ft_my_restart(my);
	if (key == 21)
	{
		values_my1(my);
		my->fractal = 4;
	}
	if (key == 22)
	{
		values_barnsley(my);
		my->fractal = 6;
	}
	if (key == 26)
	{
		values_my2(my);
		my->fractal = 7;
	}
	if (key == 28)
	{
		values_my3(my);
		my->fractal = 8;
	}
	if (key == 38)
		ft_stop_julia(my);
}

void		pereklucatel3(t_glob *my, int key)
{
	if (key == 0X74)
	{
		if (my->fractal == 6 || my->fractal == 5)
			my->maxiterations += 5;
		else
			my->maxiterations += 1;
	}
	if (key == 0X79)
	{
		my->maxiterations -= 1;
		if (my->maxiterations <= 1)
			my->maxiterations = 1;
	}
}
