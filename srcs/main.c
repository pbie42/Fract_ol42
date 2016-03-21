/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:57:30 by pbie              #+#    #+#             */
/*   Updated: 2016/03/21 14:38:41 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_fractol_init(t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "mandelbrot")))
		ft_init_mandel(m);
	if (!(ft_strcmp(m->argv, "julia")))
		ft_init_julia(m);
	if (!(ft_strcmp(m->argv, "mandelbralt")))
		ft_init_mandelbralt(m);
	if (!(ft_strcmp(m->argv, "burningship")))
		ft_init_burnship(m);
}

void			ft_print_fractol(t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "mandelbrot")))
		ft_mandelbrot(m);
	if (!(ft_strcmp(m->argv, "julia")))
		ft_julia(m);
	if (!(ft_strcmp(m->argv, "mandelbralt")))
		ft_mandelbralt(m);
	if (!(ft_strcmp(m->argv, "burningship")))
		ft_burnship(m);
}

int				main(int argc, char **argv)
{
	t_mlx		m;

	m.argv = argv[1];
	if (argc == 2 && ((!(ft_strcmp(m.argv, "mandelbrot")))
			|| (!(ft_strcmp(m.argv, "julia")))
			|| (!(ft_strcmp(m.argv, "mandelbralt")))
			|| (!(ft_strcmp(m.argv, "burningship")))))
	{
		m.mlx = mlx_init();
		m.win = mlx_new_window(m.mlx, WIN_X, WIN_Y, "fractol");
		m.im = mlx_new_image(m.mlx, FRAC_X, WIN_Y);
		m.imc = mlx_get_data_addr(m.im, &m.bpp, &m.imlen, &m.endi);
		mlx_string_put(m.mlx, m.win, 520, 240, 0x009999FF, HELLO);
		mlx_string_put(m.mlx, m.win, 460, 270, 0x009999FF, START);
		ft_fractol_init(&m);
		mlx_hook(m.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_julia_hook, &m);
		mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, ft_key_binding, &m);
		mlx_hook(m.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &m);
		mlx_mouse_hook(m.win, ft_mouse_hook, &m);
		mlx_loop_hook(m.mlx, ft_keycore, &m);
		mlx_loop(m.mlx);
	}
	else
		ft_exit("Enter 'mandelbrot', 'julia', 'mandelbralt', or 'burningship'");
	return (0);
}
