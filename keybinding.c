/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:27:22 by pbie              #+#    #+#             */
/*   Updated: 2016/03/17 11:47:59 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_key_binding(int keycode, t_mlx *m)
{
	if (keycode == PLUS1 || keycode == PLUS2)
		m->itm = 1;
	if (keycode == MINUS1 || keycode == MINUS2)
		m->itm = -1;
	if (keycode == ENTER || keycode == RETURN)
		m->res = 1;
	if (keycode == HOLD)
		m->bj = 1;
	if (keycode == ONE1 || keycode == ONE2)
		m->argv = "mandelbrot";
	if (keycode == TWO1 || keycode == TWO2)
		m->argv = "julia";
	if (keycode == THREE1 || keycode == THREE2)
		m->argv = "mandelbralt";
	if (keycode == ONE1 || keycode == ONE2 || keycode == TWO1
			|| keycode == TWO2)
		ft_fractol_init(m);
	return (0);
}

int				ft_key_release(int keycode, t_mlx *m)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == PLUS1 || keycode == PLUS2)
		m->itm = 0;
	if (keycode == MINUS1 || keycode == MINUS2)
		m->itm = 0;
	if (keycode == HOLD)
		m->bj = 0;
	if (keycode == RETURN || keycode == ENTER)
		m->res = 0;
	return (0);
}

void			ft_key_action(t_mlx *m)
{
	if (m->itm == -1 && m->max > 10)
		m->max -= 10;
	if (m->itm == 1)
		m->max += 10;
	if (m->res == 1)
		ft_fractol_init(m);
}

int				ft_keycore(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->im);
	m->im = mlx_new_image(m->mlx, WIN_X, WIN_Y);
	ft_key_action(m);
	ft_print_fractol(m);
	mlx_put_image_to_window(m->mlx, m->win, m->im, 0, 0);
	return (1);
}
