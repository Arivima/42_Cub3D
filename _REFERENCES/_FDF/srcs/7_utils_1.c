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

t_point	ft_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point	ft_distance(t_map ***map, t_draw *draw)
{
	t_point	leftest_pix;
	t_point	highest_pix;
	t_point	offset;

	leftest_pix = ft_pix_leftest(map, draw);
	highest_pix = ft_pix_highest(map, draw);
	offset.x = map[0][0]->pix_x - leftest_pix.x;
	offset.y = map[0][0]->pix_y - highest_pix.y;
	return (offset);
}
