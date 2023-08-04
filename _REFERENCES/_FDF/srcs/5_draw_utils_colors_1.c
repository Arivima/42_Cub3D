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

int	color_fade(t_map a, t_map z, t_map i)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	prog;

	prog = (ft_abs(i.pix_x - a.pix_x) + ft_abs(i.pix_y - a.pix_y)) * \
	100 / (ft_abs(z.pix_x - a.pix_x) + ft_abs(z.pix_y - a.pix_y));
	t = ((get_t(z.color) - get_t(a.color)) * prog / 100) + get_t(a.color);
	r = ((get_r(z.color) - get_r(a.color)) * prog / 100) + get_r(a.color);
	g = ((get_g(z.color) - get_g(a.color)) * prog / 100) + get_g(a.color);
	b = ((get_b(z.color) - get_b(a.color)) * prog / 100) + get_b(a.color);
	return (create_trgb(t, r, g, b));
}

int	get_opposite_color(int color)
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
