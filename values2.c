/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:22:28 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/21 13:22:30 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		values_serpinsky(t_glob *my)
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

void		values_burningship(t_glob *my)
{
	my->maxiterations = 50;
	my->zoom = 220;
	my->x_move = 0;
	my->y_move = -1;
	my->color = 0x010602;
}

void		values_barnsley(t_glob *my)
{
	my->x_move = 0;
	my->y_move = 0;
	my->zoom = 0.057;
	my->maxiterations = 50;
	my->color = 0X990314;
}
