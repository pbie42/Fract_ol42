/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:54:17 by pbie              #+#    #+#             */
/*   Updated: 2016/03/15 17:42:42 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_julia(t_mlx *m)
{
	m->x1 = -1.6;
	m->x2 = 1;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom = 250;
	m->im_x = (m->x2 - m->x1) * m->zoom + 150;
	m->im_y = (m->y2 - m->y1) * m->zoom;
	m->max = 90;
	m->c_r = 0.285;
	m->c_i = 0.01;
}

void			ft_julia(t_mlx *m)
{
	m->x = -1;
	while (++m->x < m->im_x)
	{
		m->y = -1;
		while (++m->y < m->im_y)
		{
			m->z_r = m->x / m->zoom + m->x1;
			m->z_i = m->y / m->zoom + m->y1;
			m->i = 0;
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && m->i < m->max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = 2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			if (m->i == m->max)
				ft_put_pixel(m, m->x, m->y, 0xFFFFFF);
			else
				ft_put_pixel(m, m->x, m->y, m->i * 1895750);
		}
	}
}

int				ft_julia_hook(int x, int y, t_mlx *m)
{
	if (!(ft_strcmp(m->argv, "julia")) && x <= WIN_X && y <= WIN_Y
			&& x > 0 && y > 0 && m->bj == 0)
	{
		m->c_r = (float)(x + 400 - WIN_X) / 300;
		m->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (1);
}
