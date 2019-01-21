/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:21:14 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/13 14:21:16 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_glob my;

	if (argc != 2)
		error();
	ft_usage(argv[1], &my);
	new_window(&my);
	return (0);
}
