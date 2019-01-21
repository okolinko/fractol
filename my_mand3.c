/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mand3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:09:46 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/21 13:09:47 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pxl_to_img5(t_glob *my, int x, int y, int color)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		color = mlx_get_color_value(my->mlx_ptr, color);
		ft_memcpy(my->addr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

int			ft_my_mand3_help2(t_glob *my, int *flag, t_mandel *sv)
{
	unsigned int		n;
	double				d;

	d = 0;
	n = 0;
	while (n++ < my->maxiterations)
	{
		sv->zr_2 = sv->zr * sv->zr;
		sv->zi_2 = sv->zi * sv->zi;
		if (sv->zr_2 + sv->zi_2 > 1.0E5)
		{
			*flag = 0;
			break ;
		}
		sv->tmp = (pow(sv->zr, 3) - (3 * (sv->zr * pow(sv->zi, 2))) + sv->cr);
		sv->zi = ((3 * pow(sv->zr, 2) * sv->zi) - (pow(sv->zi, 3)) + sv->ci);
		sv->zr = sv->tmp;
	}
	return (n);
}

void		ft_find_my_mand3(t_glob *my, int x, int y, t_mandel *sv)
{
	int flag;
	int n;

	while (x++ < WIDTH / 2)
	{
		sv->cr = (float)x / (my->zoom) + my->x_move - 0.5;
		sv->zr = sv->cr;
		sv->zi = sv->ci;
		flag = 1;
		n = ft_my_mand3_help2(my, &flag, sv);
		if (flag)
		{
			put_pxl_to_img5(my, x + WIDTH / 2, y + HEIGHT / 2, 0x000000);
		}
		else
		{
			put_pxl_to_img5(my, x + WIDTH / 2, y + HEIGHT / 2, my->color * n);
		}
	}
}

void		ft_my_mand3(t_glob *my, int x, int y, int y_max)
{
	t_mandel sv;

	while (y < y_max)
	{
		sv.ci = y / (my->zoom) + (my->y_move) + 0.1;
		x = (WIDTH / 2) * -1;
		ft_find_my_mand3(my, x, y, &sv);
		y++;
	}
}

void		restart7(t_glob *my)
{
	my->maxiterations = 25;
	my->zoom = 200;
	my->x_move = 0.4;
	my->y_move = 0;
	my->color = 265;
}
