/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:27 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:09:28 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_pix_lowest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.y < tmp[y][x].pix_y)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_highest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.y > tmp[y][x].pix_y)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_rightest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.x < tmp[y][x].pix_x)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_leftest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.x > tmp[y][x].pix_x)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}
