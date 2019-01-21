/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:05:15 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/19 16:05:16 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		random_for_serp(int n, int i)
{
	int		dot;

	if (n < 11)
	{
		dot = random() % 10;
		if (dot < n && dot > 0)
			return (dot);
	}
	else if (n > 10)
	{
		dot = random() % 100;
		if (dot < n && dot > 0)
			return (dot);
	}
	random_for_serp(n, i);
	return (2);
}

void		put_pxl_to_img2(t_glob *my, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		color = mlx_get_color_value(my->mlx_ptr, color);
		ft_memcpy(my->addr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void		color_frst(t_glob *my, t_serpinsky *sv)
{
	sv->x = (sv->x + my->serpinsky.frst_x) / 2;
	sv->y = (sv->y + my->serpinsky.frst_y) / 2;
	put_pxl_to_img2(my, sv->x, sv->y, my->color);
}

void		find_dots_serpinskogo(t_glob *my, int i, int tmp)
{
	t_serpinsky sv;

	sv.x = (my->serpinsky.frst_x + my->serpinsky.scnd_x) / 2;
	sv.y = (my->serpinsky.frst_y + my->serpinsky.scnd_y) / 2;
	while ((unsigned int)i++ < my->maxiterations)
	{
		tmp = random_for_serp(10, 1);
		if (tmp > 0 && tmp < 4)
			color_frst(my, &sv);
		else if (tmp > 3 && tmp < 7)
		{
			sv.x = (sv.x + my->serpinsky.scnd_x) / 2;
			sv.y = (sv.y + my->serpinsky.scnd_y) / 2;
			put_pxl_to_img2(my, sv.x, sv.y, my->color);
		}
		else if (tmp > 6 && tmp < 10)
		{
			sv.x = (sv.x + my->serpinsky.thrd_x) / 2;
			sv.y = (sv.y + my->serpinsky.thrd_y) / 2;
			put_pxl_to_img2(my, sv.x, sv.y, my->color);
		}
	}
}
