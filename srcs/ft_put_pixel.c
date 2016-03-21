/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:38:03 by pbie              #+#    #+#             */
/*   Updated: 2016/03/15 16:40:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int			*tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&mlx->imc[(y * mlx->imlen) + (x * (mlx->bpp / 8))];
	*tmp = color;
}
