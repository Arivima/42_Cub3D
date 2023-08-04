/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_draw_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:11 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:09:12 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, t_point a, int color)
{
	char	*dst;

	if (a.x > 10 && a.x < (WIN_WIDTH - 10) && a.y > 10 && a.y < \
	(WIN_HEIGHT - 10))
	{
		dst = img->addr + (a.y * img->line_length + a.x * \
		(img->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

int	ft_sign(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
	return (0);
}

void	ft_line_bresenham(t_img *img, t_point a, t_point b, int color)
{
	t_bres	bres;

	bres.dx = ft_abs(b.x - a.x);
	bres.sx = ft_sign(a.x, b.x);
	bres.dy = -ft_abs(b.y - a.y);
	bres.sy = ft_sign(a.y, b.y);
	bres.err = bres.dx + bres.dy;
	while (a.x != b.x || a.y != b.y)
	{
		my_mlx_pixel_put(img, a, color);
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.dy)
		{
			bres.err += bres.dy;
			a.x += bres.sx;
		}
		if (bres.e2 <= bres.dx)
		{
			bres.err += bres.dx;
			a.y += bres.sy;
		}
	}
}

void	ft_line_bresenham_map(t_img *img, t_map a, t_map b)
{
	t_bres	bres;
	t_map	i;

	i = a;
	bres.dx = ft_abs(b.pix_x - i.pix_x);
	bres.sx = ft_sign(i.pix_x, b.pix_x);
	bres.dy = -ft_abs(b.pix_y - i.pix_y);
	bres.sy = ft_sign(i.pix_y, b.pix_y);
	bres.err = bres.dx + bres.dy;
	while (i.pix_x != b.pix_x || i.pix_y != b.pix_y)
	{
		my_mlx_pixel_put(img, ft_point(i.pix_x, i.pix_y), color_fade(a, b, i));
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.dy)
		{
			bres.err += bres.dy;
			i.pix_x += bres.sx;
		}
		if (bres.e2 <= bres.dx)
		{
			bres.err += bres.dx;
			i.pix_y += bres.sy;
		}
	}
}
