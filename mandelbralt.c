/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbralt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:18:37 by pbie              #+#    #+#             */
/*   Updated: 2016/03/17 11:44:01 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_mandelbralt(t_mlx *m)
{
	m->x1 = -2.1;
	m->x2 = 1;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom = 250;
	m->im_x = (m->x2 - m->x1) * m->zoom + 50;
	m->im_y = (m->y2 - m->y1) * m->zoom;
	m->max = 90;
}

void			ft_mandelbralt(t_mlx *m)
{
	m->x = -1;
	while (++m->x < m->im_x)
	{
		m->y = -1;
		while (++m->y < m->im_y)
		{
			m->c_r = m->x / m->zoom + m->x1;
			m->c_i = m->y / m->zoom + m->y1;
			m->z_r = 0;
			m->z_i = 0;
			m->i = 0;
			while (m->z_r * m->z_r + m->z_i * m->z_i < 4 && m->i < m->max)
			{
				m->tmp = m->z_r;
				m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
				m->z_i = -2 * m->z_i * m->tmp + m->c_i;
				m->i++;
			}
			if (m->i == m->max)
				ft_put_pixel(m, m->x, m->y, 0x000000);
			else
				ft_put_pixel(m, m->x, m->y, m->i * 1835750);
		}
	}
}
