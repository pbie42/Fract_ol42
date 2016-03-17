/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:57:30 by pbie              #+#    #+#             */
/*   Updated: 2016/03/17 14:50:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_putset(t_mlx *mlx)
{
	int			y;

	y = 0;
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 32, 0xccccff, L_CONTROLS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 80, 0xccccff, L_PAGE_UP);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 96, 0xccccff, L_PAGE_DOWN);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 112, 0xccccff, L_PLUS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 128, 0xccccff, L_MINUS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 144, 0xccccff, L_MANDEL);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 160, 0xccccff, L_JULIA);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 176, 0xccccff, L_MANDALT);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 192, 0xccccff, L_TRANS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 176, 0xccccff, L_HOLD);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 192, 0xccccff, L_RESET);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 208, 0xccccff, L_ESC);
}

void			ft_fractol_init(t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "mandelbrot")))
		ft_init_mandel(m);
	if (!(ft_strcmp(m->argv, "julia")))
		ft_init_julia(m);
	if (!(ft_strcmp(m->argv, "mandelbralt")))
		ft_init_mandelbralt(m);
}

void			ft_print_fractol(t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "mandelbrot")))
		ft_mandelbrot(m);
	if (!(ft_strcmp(m->argv, "julia")))
		ft_julia(m);
	if (!(ft_strcmp(m->argv, "mandelbralt")))
		ft_mandelbralt(m);
}

int				main(int argc, char **argv)
{
	t_mlx		m;
	int			c_x;
	int			c_y;

	m.argv = argv[1];
	if (argc == 2 && ((!(ft_strcmp(m.argv, "mandelbrot")))
			|| (!(ft_strcmp(m.argv, "julia")))
			|| (!(ft_strcmp(m.argv, "mandelbralt")))))
	{
		ft_putendl(argv[1]);
		c_x = WIN_X * 2 / 5;
		c_y = WIN_Y * 2 / 5;
		m.mlx = mlx_init();
		m.win = mlx_new_window(m.mlx, WIN_X, WIN_Y, "fractol");
		m.im = mlx_new_image(m.mlx, FRAC_X, WIN_Y);
		m.imc = mlx_get_data_addr(m.im, &m.bpp, &m.imlen, &m.endi);
		ft_fractol_init(&m);
		mlx_string_put(m.mlx, m.win, c_x + 40, c_y, 0x009999FF, HELLO);
		mlx_string_put(m.mlx, m.win, c_x - 20, c_y + 30, 0x009999FF, START);
		mlx_hook(m.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_julia_hook, &m);
		mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, ft_key_binding, &m);
		mlx_hook(m.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &m);
		mlx_mouse_hook(m.win, ft_mouse_hook, &m);
		mlx_loop_hook(m.mlx, ft_keycore, &m);
		mlx_loop(m.mlx);
	}
	else
		ft_exit("Error: Wrong Number of Arguments");
	return (0);
}
