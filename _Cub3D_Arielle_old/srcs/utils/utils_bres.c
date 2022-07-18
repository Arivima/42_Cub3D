/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (img && img->addr && img->line_length && img->bits_per_pixel\
	&& x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT && color >= 0 && color <= 0xFFFFFFFF)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
	// else if (!img)
	// 	return (printf("error pix put IMG\n"));
	// else if (x < 0 || x >= WIN_WIDTH)
	// 	return (printf("error pix put X\n"));
	// else if (y < 0 || y >= WIN_HEIGHT)
	// 	return (printf("error pix put Y\n"));		
	// else if (color < 0 || color > 0xFFFFFFFF)
	// 	return (printf("error pix put COLOR %X\n", color));		
	// else
	// 	return (printf("error pix put\n"));
	return (0);
}

int	ft_sign(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
	return (0);
}

void	ft_line_bresenham_color(t_img *img, t_point a, t_point b, int color)
{
	t_bres	bres;
	t_point	i;

	i = a;
	bres.dx = ft_abs(b.x - i.x);
	bres.sx = ft_sign(i.x, b.x);
	bres.dy = -ft_abs(b.y - i.y);
	bres.sy = ft_sign(i.y, b.y);
	bres.err = bres.dx + bres.dy;
	while (i.x != b.x || i.y != b.y)
	{
		ft_mlx_pixel_put(img, i.x, i.y, color);
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.dy)
		{
			bres.err += bres.dy;
			i.x += bres.sx;
		}
		if (bres.e2 <= bres.dx)
		{
			bres.err += bres.dx;
			i.y += bres.sy;
		}
	}
}
