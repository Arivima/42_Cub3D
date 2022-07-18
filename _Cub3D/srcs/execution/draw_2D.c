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

int	ft_get_color_2d(t_hold *hold, t_pt i, t_pt n)
{
	int	color;

	color = COLOR_VOID;
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
	t_pt	pos;
	t_pt	max;
	t_pt	n;
	int		color;

	debug("    ft_2dmap_map");
	pos.x = START_2D_X;
	pos.y = START_2D_Y;
	max.x = START_2D_X + ft_to_pxl(hold, hold->map_w);
	max.y = START_2D_Y + ft_to_pxl(hold, hold->map_h);
	while (pos.y < max.y)
	{
		pos.x = START_2D_X;
		while (pos.x < max.x)
		{
			n.x = (pos.x - START_2D_X) % hold->ppu;
			n.y = (pos.y - START_2D_Y) % hold->ppu;
			color = ft_get_color_2d(hold, ft_point(pos.x, pos.y), n);
			if (color != COLOR_VOID)
				ft_mlx_pixel_put(hold->img, pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
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
			color = COLOR_RAYCASTING;
		ft_line_bresenham_color_map(hold->img, hold, i, color);
	}
	return (0);
}

void	ft_draw_circle(t_hold *hold, t_pt pt, int r, t_pt color)
{
	float	i;
	float	angle;
	float	x1;
	float	y1;
	t_pt	temp;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		temp = ft_point(pt.x + x1, pt.y + y1);
		ft_line_bresenham_color(hold->img, ft_point(pt.x, pt.y), temp, color.x);
		ft_mlx_pixel_put(hold->img, pt.x + x1, pt.y + y1, color.y);
		i += 0.1;
	}
}

int	ft_put_2dmap(t_hold *hold)
{
	t_pt	temp;

	debug("   ft_put_2dmap");
	ft_2dmap_map(hold);
	ft_2dmap_raycasting(hold);
	temp = ft_point(hold->pix_x, hold->pix_y);
	debug("    ft_2dmap_player\n");
	ft_draw_circle(hold, temp, hold->ppu / 2, ft_point(WHITE_GREY, WHITE_GREY));
	return (0);
}
