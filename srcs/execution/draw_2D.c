/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:17:34 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:17:38 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_put_2dmap(t_hold *hold)
{
	debug("   ft_put_2dmap");
	ft_2dmap_map(hold);
	ft_2dmap_raycasting(hold);
	ft_2dmap_player(hold);
	return (0);
}

int	ft_get_color_2d(t_hold *hold, t_point i, t_point n)
{
	int	color;

	color = BLACK;
	if (n.y && n.x)
	{
		if (ft_is_point_on_map(hold, i, EMPTY) \
		|| ft_is_point_on_map(hold, i, DOOR_OPEN))
			color = COLOR_EMPTY;
		else if (ft_is_point_on_map(hold, i, SPRITE))
			color = COLOR_SPRITE;
		else if (ft_is_point_on_map(hold, i, ENEMY))
			color = COLOR_ENEMY;
		else if (ft_is_point_on_map(hold, i, DOOR_CLOSED))
			color = COLOR_DOORS;
		else if (!ft_is_point_on_map(hold, i, 32))
			color = COLOR_WALLS;
	}
	else if (!ft_is_point_on_map(hold, i, 32))
		color = COLOR_BORDER;
	return (color);
}

int	ft_2dmap_map(t_hold *hold)
{
	int		xi;
	int		yi;
	int		xmax;
	int		ymax;
	t_point	n;

	debug("    ft_2dmap_map");
	xi = START_2D_X;
	yi = START_2D_Y;
	xmax = START_2D_X + ft_to_pxl(hold, hold->map_w);
	ymax = START_2D_Y + ft_to_pxl(hold, hold->map_h);
	while (yi < ymax)
	{
		xi = START_2D_X;
		while (xi < xmax)
		{
			n.x = (xi - START_2D_X) % hold->ppu;
			n.y = (yi - START_2D_Y) % hold->ppu;
			ft_mlx_pixel_put(hold->img, xi, yi, \
			ft_get_color_2d(hold, ft_point(xi, yi), n));
			xi++;
		}
		yi++;
	}
	return (0);
}

int	ft_2dmap_raycasting(t_hold *hold)
{
	int		color;
	int		i;

	debug("    ft_2dmap_raycasting");
	i = -1;
	while (++i < WIN_WIDTH)
	{
		color = ft_get_wall_color(hold, i);
		if (i >= (int)WIN_WIDTH / 2 * 0.94 && i <= (int)WIN_WIDTH / 2 * 1.06)
			color = RED;
		ft_line_bresenham_color(hold->img, ft_point(hold->pix_x, hold->pix_y), \
		ft_point((hold->hit[IX][i]), (hold->hit[IY][i])), color);
	}
	return (0);
}

int	ft_2dmap_player(t_hold *hold)
{
	debug("    ft_2dmap_player\n");
	if (hold)
		;
	return (0);
}
