/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int	get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

int	get_b(int trgb)
{
	return ((trgb & 0xFF));
}

int	ft_get_opposite_color(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(t, r, g, b));
}

int	ft_get_img_color(t_img *img, t_pt pt)
{
	unsigned char	rgb[3];
	int				dst;

	if (!img || pt.x < 0 || pt.x > WIN_WIDTH || pt.y < 0 || pt.y > WIN_HEIGHT)
		return (ft_error("ft_get_img_color"));
	dst = (pt.y * img->line_length) + (img->bits_per_pixel / 8 * pt.x);
	rgb[0] = (unsigned char)img->addr[dst + 2];
	rgb[1] = (unsigned char)img->addr[dst + 1];
	rgb[2] = (unsigned char)img->addr[dst];
	return ((int)rgb[0] << 16 | (int)rgb[1] << 8 | (int)rgb[2]);
}
