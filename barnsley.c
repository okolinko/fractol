/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:28:27 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/20 18:28:28 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_color_barnsley(t_glob *my, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		color = mlx_get_color_value(my->mlx_ptr, color);
		ft_memcpy(my->addr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	ft_barnsley_help(t_barnsley *sv)
{
	if (sv->p <= 85 && sv->p > 1)
	{
		sv->x = 0.84 * sv->x - 0.045 * sv->y;
		sv->y = 0.045 * sv->t + 0.86 * sv->y + 2.6;
	}
	else if (sv->p <= 92 && sv->p > 85)
	{
		sv->x = 0.20 * sv->x - 0.26 * sv->y;
		sv->y = 0.23 * sv->t + 0.25 * sv->y + 2.6;
	}
	else if (sv->p <= 99 && sv->p > 92)
	{
		sv->x = -0.135 * sv->x + 0.28 * sv->y;
		sv->y = 0.26 * sv->t + 0.245 * sv->y + 1.44;
	}
	else
	{
		sv->x = 0.0;
		sv->y = 0.16 * sv->y;
	}
}

void	find_barnsley(t_glob *my)
{
	int			zom;
	t_barnsley	sv;

	sv.mid_x = WIDTH / 2;
	sv.mid_y = HEIGHT - 100;
	zom = trunc(my->zoom * sv.mid_y);
	sv.x = 1.0;
	sv.y = 1.0;
	sv.k = 1;
	while (sv.k++ < my->maxiterations)
	{
		sv.p = random() % 100;
		sv.t = sv.x;
		ft_barnsley_help(&sv);
		ft_pixel_color_barnsley(my, sv.mid_x + round(zom * sv.x) + my->x_move,
				sv.mid_y - round(zom * sv.y) + 35 + my->y_move, my->color);
	}
}
