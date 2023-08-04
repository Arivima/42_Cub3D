/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	ft_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

int	ft_to_pxl(t_hold *hold, int pt)
{
	return (pt * hold->ppu);
}

int	ft_to_pt(t_hold *hold, int pxl)
{
	return (pxl / hold->ppu);
}

int	ft_to_world_x(t_hold *hold, int pxl)
{
	return ((int)((pxl - START_2D_X) * (WIN_WIDTH / hold->ppu)));
}

int	ft_to_world_y(t_hold *hold, int pxl)
{
	return ((int)((pxl - START_2D_Y) * (WIN_WIDTH / hold->ppu)));
}

int ft_is_point_on_map(t_hold *hold, t_point point, int place)
{
	return (hold->map[ft_to_pt(hold, point.y - START_2D_Y)][ft_to_pt(hold, point.x - START_2D_X)] == place);
}

