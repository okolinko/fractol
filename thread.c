/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:13:41 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/18 13:13:42 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		*ft_comand_threads(void *pot)
{
	t_threads	*potok;
	int			y;
	int			y_max;

	potok = (t_threads*)pot;
	y = (HEIGHT / N) * potok->n;
	y_max = HEIGHT / N * (potok->n + 1);
	if (potok->ptr->fractal == 1)
		ft_mandelbrot_init(potok->ptr, 0, y, y_max);
	if (potok->ptr->fractal == 2)
		ft_julia_init(potok->ptr, 0, y, y_max);
	if (potok->ptr->fractal == 3)
		burningship(potok->ptr, 0, y, y_max);
	if (potok->ptr->fractal == 4)
		ft_my_mand(potok->ptr, 0, y, y_max);
	if (potok->ptr->fractal == 5)
		find_dots_serpinskogo(potok->ptr, 0, 0);
	if (potok->ptr->fractal == 6)
		find_barnsley(potok->ptr);
	if (potok->ptr->fractal == 7)
		ft_my_mand2(potok->ptr, 0, y, y_max);
	if (potok->ptr->fractal == 8)
		ft_my_mand3(potok->ptr, 0, y, y_max);
	pthread_exit(0);
}

void		ft_threads(t_glob *my)
{
	t_threads		potok[N];
	int				i;
	int				n;

	n = -26;
	i = -1;
	while (++i < N)
	{
		++n;
		potok[i].ptr = my;
		potok[i].n = n;
		pthread_create(&potok[i].threads, NULL, ft_comand_threads, &potok[i]);
	}
	i = -1;
	while (++i < N)
		pthread_join(potok[i].threads, NULL);
}
