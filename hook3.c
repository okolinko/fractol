/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:15:27 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/21 11:15:29 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		hlp_zoom_mouse(t_glob *my)
{
	my->serpinsky.frst_y -= 1;
	my->serpinsky.scnd_y += 1;
	my->serpinsky.thrd_x -= 1;
	my->serpinsky.thrd_y -= 1;
	my->maxiterations -= 1;
	my->serpinsky.frst_x += 1;
}

void		zoom_serpi_up(t_glob *my)
{
	if (if_negative(my) == 1)
	{
		my->serpinsky.frst_y -= 100;
		my->serpinsky.scnd_y += 100;
		my->serpinsky.thrd_x -= 100;
		my->serpinsky.thrd_y -= 100;
		my->maxiterations -= 100;
		my->serpinsky.frst_x += 100;
	}
	else if (my->serpinsky.frst_x + 20 <= my->serpinsky.thrd_x)
	{
		my->serpinsky.frst_y -= 10;
		my->serpinsky.scnd_y += 10;
		my->serpinsky.thrd_x -= 10;
		my->serpinsky.thrd_y -= 10;
		my->maxiterations -= 10;
		my->serpinsky.frst_x += 10;
	}
	if (my->serpinsky.frst_x + 2 <= my->serpinsky.thrd_x)
		hlp_zoom_mouse(my);
}

void		restart5(t_glob *my)
{
	my->x_move = 0;
	my->y_move = 0;
	my->zoom = 0.057;
	my->maxiterations = 50;
	my->color = 0X990314;
}

int			if_positiv(t_glob *my)
{
	if (my->serpinsky.thrd_x + WIDTH > 10E8)
		return (0);
	return (1);
}

int			if_negative(t_glob *my)
{
	if (my->serpinsky.thrd_x - my->serpinsky.frst_x < 250)
		return (0);
	return (1);
}
