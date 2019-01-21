/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <akolinko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:23:53 by akolinko          #+#    #+#             */
/*   Updated: 2018/11/13 14:23:54 by akolinko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1200
# define WIDTH 1200
# define N 50
# define THREAD_WIDTH 10
# define THREAD_NUMBER 120
# define F "Fractol - akolinko"
# define Q "UP max iterations   - page Up"
# define W "Down max iterations - page Down"
# define E "Color               - num 1 - 9"
# define R "ZUM                 - maus end (+  -)"
# define T "Restart             - space"
# define U "Stop julia          - J"
# define I "Fractol selection   - (1...8)"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

typedef	struct		s_mandel
{
	double			ci;
	double			cr;
	double			tmp;
	double			zr;
	double			zr_2;
	double			zi;
	double			zi_2;
}					t_mandel;

typedef struct		s_barnsley
{
	double			x;
	double			y;
	double			t;
	int				p;
	int				mid_x;
	int				mid_y;
	long			k;
}					t_barnsley;

typedef struct		s_serpinsky
{
	int				x;
	int				y;
	int				frst_x;
	int				frst_y;
	int				scnd_x;
	int				scnd_y;
	int				thrd_x;
	int				thrd_y;
}					t_serpinsky;

typedef struct		s_glob
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				fractal;
	char			*name;
	double			zoom;
	unsigned int	maxiterations;
	int				x;
	int				y;
	unsigned int	n;
	int				color;
	void			*image;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			y_move;
	double			x_move;
	double			mousere;
	double			mouseim;
	int				stop_julia;
	double			re;
	double			im;
	t_serpinsky		serpinsky;
	t_barnsley		barnsley;

}					t_glob;

typedef struct		s_threads
{
	t_glob			*ptr;
	pthread_t		threads;
	int				n;

}					t_threads;

typedef struct		s_julia
{
	double			re;
	double			im;
	double			re_old;
	double			im_old;
}					t_julia;

void				error(void);
void				error1(void);
void				ft_usage(char *str, t_glob *my);
void				new_window(t_glob *my);
void				values_mandelbrot(t_glob *my);
void				drav_fractol(t_glob *my);
void				put_pxl_to_img(t_glob *my, int x, int y, int color);
void				chec_value(t_glob *my);
void				ft_string_put(t_glob *my);
void				ft_mandelbrot_init(t_glob *my, int x, int y, int y_max);
int					deal_key(int key, t_glob *my);
void				key5(t_glob *my);
void				color_fractol(int key, t_glob *my);
void				ft_restart(t_glob *my);
void				ft_threads(t_glob *my);
void				ft_julia_init(t_glob *my, int x, int y, int y_max);
int					mouse_hook(int mousecode, int x, int y, t_glob *my);
void				ft_julia_help(t_glob *my, int x, int y, int y_max);
void				ft_my_mand(t_glob *my, int x, int y, int y_max);
void				values_julia(t_glob *my);
void				values_serpinsky(t_glob *fract);
void				find_dots_serpinskogo(t_glob *my, int iter, int tmp);
int					ft_count_pixel(t_glob *ptr, int x, int y);
int					if_negative(t_glob *my);
int					if_positiv(t_glob *fract);
void				zoom_serpi_up(t_glob *my);
void				zoom_serpi(t_glob *my);
void				ft_restart2(t_glob *my);
void				values_barnsley(t_glob *ptr);
void				burningship(t_glob *my, int x, int y, int y_max);
void				find_barnsley(t_glob *ptr);
void				restart3(t_glob *my);
void				values_my1(t_glob *my);
void				values_burningship(t_glob *my);
void				restart4(t_glob *my);
void				restart5(t_glob *my);
void				values_my2(t_glob *my);
void				ft_my_mand2(t_glob *my, int x, int y, int y_max);
void				restart6(t_glob *my);
void				ft_my_mand3(t_glob *my, int x, int y, int y_max);
void				values_my3(t_glob *my);
void				restart7(t_glob *my);
void				zoom_serpi_up(t_glob *my);
void				hlp_zoom_mouse(t_glob *my);
void				zoom_serpinskogo(t_glob *my, int mousecode);
void				ft_stop_julia(t_glob *my);
void				ft_my_restart(t_glob *my);
void				my_zom(t_glob *my);
void				pereklucatel(t_glob *my, int key);
void				pereklucatel2(t_glob *my, int key);
void				pereklucatel3(t_glob *my, int key);

#endif
