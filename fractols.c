/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:48:37 by pbie              #+#    #+#             */
/*   Updated: 2016/03/11 18:22:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_mbset(t_mb *mb)
{
	mb->row = 0;
	mb->col = 0;
	mb->height = 1080;
	mb->width = 1920;
	mb->max = 1000;
	mb->iter = 0;
}

void			ft_mbset2(t_mb *mb)
{
	mb->x_new = mb->x * mb->x - mb->y * mb->y + mb->c_re;
	mb->y = 2 * mb->x * mb->y + mb->c_im;
	mb->x = mb->x_new;
}

void			ft_mandelbrot(t_mlx *mlx)
{
	t_mb		mb;

	ft_mbset(&mb);
	while (mb.row < mb.height)
	{
		while (mb.col < mb.width)
		{
			mb.c_re = (mb.col - mb.width / 2) * 4 / mb.width;
			mb.c_im = (mb.row - mb.height / 2) * 4 / mb.width;
			mb.x = 0;
			mb.y = 0;
			mb.iter = 0;
			while (mb.x * mb.x + mb.y * mb.y <= 4 && mb.iter < mb.max)
			{
				ft_mbset2(&mb);
				mb.iter++;
			}
			if (mb.iter < mb.max)
				ft_put_pixel(mlx, mb.col, mb.row, 0x00FFFFFF);
			else
				ft_put_pixel(mlx, mb.col, mb.row, 0x00000000);
			mb.col++;
		}
		mb.row++;
	}
}
