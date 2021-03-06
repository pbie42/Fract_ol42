/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:48:44 by pbie              #+#    #+#             */
/*   Updated: 2016/03/21 14:53:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_zoom_in(int x, int y, t_mlx *m)
{
	m->zoom *= 2;
	m->tmpx = m->x1 + x * (m->x2 - m->x1) / (FRAC_X - 50);
	m->tmpy = m->y1 + y * (m->y2 - m->y1) / (WIN_Y - 20);
	m->tmpx2 = m->x1;
	m->tmpy2 = m->y1;
	m->x1 = m->tmpx - (m->x2 - m->x1) / 4;
	m->x2 = m->tmpx + (m->x2 - m->tmpx2) / 4;
	m->y1 = m->tmpy - (m->y2 - m->y1) / 4;
	m->y2 = m->tmpy + (m->y2 - m->tmpy2) / 4;
}

void			ft_zoom_out(int x, int y, t_mlx *m)
{
	if (m->zoom > 250)
	{
		m->zoom /= 2;
		m->tmpx = m->x1 + x * (m->x2 - m->x1) / FRAC_X;
		m->tmpy = m->y1 + y * (m->y2 - m->y1) / WIN_Y;
		m->tmpx2 = m->x1;
		m->tmpy2 = m->y1;
		m->x1 = m->tmpx - (m->x2 - m->x1);
		m->x2 = m->tmpx + (m->x2 - m->tmpx2);
		m->y1 = m->tmpy - (m->y2 - m->y1);
		m->y2 = m->tmpy + (m->y2 - m->tmpy2);
	}
}

int				ft_mouse_hook(int keycode, int x, int y, t_mlx *m)
{
	if (!(m->check))
		ft_settings(m);
	if (y > 0 && m->check)
	{
		if ((keycode == 1 || keycode == 5) && x <= FRAC_X)
			ft_zoom_in(x, y, m);
		if ((keycode == 2 || keycode == 4) && x <= FRAC_X)
			ft_zoom_out(x, y, m);
	}
	m->check = 1;
	return (1);
}
