/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:53 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:56 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_raycasting(t_hold *hold)
{
	int		i;
	t_pt_d	dir;
	t_pt_d	plane;
	float	camera_x;
	t_pt_d	ray_dir;

	debug("   ft_raycasting");
	ft_memset(hold->hit, 0, sizeof(int) * 5 * WIN_WIDTH);
	dir.x = cos(hold->pos_a);
	dir.y = sin(hold->pos_a);
	plane.x = cos(hold->pos_a + M_PI_2) * FOV_R;
	plane.y = sin(hold->pos_a + M_PI_2) * FOV_R;
	i = -1;
	while (++i < WIN_WIDTH)
	{
		camera_x = ((float)(2 * i)) / (float)WIN_WIDTH - 1.0;
		ray_dir.x = dir.x + (plane.x * camera_x);
		ray_dir.y = dir.y + (plane.y * camera_x);
		hold->hit[IX][i] = ray_dir.x;
		hold->hit[IY][i] = ray_dir.y;
		ft_line_hit(hold, hold->pl_w, hold->pl_map, i);
	}
	return (0);
}

int	ft_get_wall_color(t_hold *hold, int i)
{
	int	color;

	color = BLACK;
	if (hold->hit[WALL_ORIENTATION][i] == e_wall_north)
		color = COLOR_WALL_NORTH;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_south)
		color = COLOR_WALL_SOUTH;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_east)
		color = COLOR_WALL_EAST;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_west)
		color = COLOR_WALL_WEST;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_angle)
		color = COLOR_WALL_ANGLE;
	return (color);
}
