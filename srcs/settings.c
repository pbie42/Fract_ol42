/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:11:44 by pbie              #+#    #+#             */
/*   Updated: 2016/03/21 15:06:29 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_settings(t_mlx *m)
{
	int			x;
	int			y;

	x = FRAC_X;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			ft_put_pixel(m, x, y, 0x000000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->im, FRAC_X, 0);
	ft_putset(m);
}

void			ft_julia_set(t_mlx *m)
{
	int			y;

	y = 0;
	mlx_string_put(m->mlx, m->win, FRAC_X, y + 304, 0xccccff, L_TRANS);
	mlx_string_put(m->mlx, m->win, FRAC_X, y + 320, 0xccccff, L_OVER);
	mlx_string_put(m->mlx, m->win, FRAC_X, y + 336, 0xccccff, L_HOLD);
}

void			ft_putset(t_mlx *mlx)
{
	int			y;

	y = 0;
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 32, 0xccccff, L_CONTROLS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 80, 0xccccff, L_PAGE_UP);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 96, 0xccccff, L_SCROLL_D);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 112, 0xccccff, L_PAGE_DOWN);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 128, 0xccccff, L_SCROLL_U);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 144, 0xccccff, L_PLUS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 160, 0xccccff, L_MINUS);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 176, 0xccccff, L_MANDEL);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 192, 0xccccff, L_JULIA);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 208, 0xccccff, L_MANDALT);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 224, 0xccccff, L_BURN);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 240, 0xccccff, L_RESET);
	mlx_string_put(mlx->mlx, mlx->win, FRAC_X, y + 256, 0xccccff, L_ESC);
	if (!(ft_strcmp(mlx->argv, "julia")))
		ft_julia_set(mlx);
}
