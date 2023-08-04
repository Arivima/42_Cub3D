/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:08:51 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:08:54 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_map_color(t_img *img, t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	while (y + 1 <= draw->height)
	{
		x = 0;
		while (x + 1 <= draw->width)
		{
			if (x + 1 < draw->width && y + 1 < draw->height)
			{
				ft_line_bresenham_map(img, tmp[y][x], tmp[y][x + 1]);
				ft_line_bresenham_map(img, tmp[y][x], tmp[y + 1][x]);
			}
			if (x + 1 == draw->width && y + 1 < draw->height)
				ft_line_bresenham_map(img, tmp[y][x], tmp[y + 1][x]);
			if (y + 1 == draw->height && x + 1 < draw->width)
				ft_line_bresenham_map(img, tmp[y][x], tmp[y][x + 1]);
			x++;
		}
		y++;
	}
}
