/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <math.h> // math lib

int	ft_is_valid_player_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	ft_value_pos(t_hold *hold, t_point pos)
{
	hold->pos_x = pos.x;
	hold->pos_y = pos.y;
	hold->pos_a = ft_init_angle_direction(hold->map[pos.y][pos.x]);
	if (hold->pos_a == ERR)
		return (ERR);
	hold->map[pos.y][pos.x] = '0';
	return (0);
}

int	ft_init_map_pt(t_hold *hold)
{
	int	x;
	int	y;

	debug("ft_init_player");
	x = -1;
	y = -1;
	while (hold->map[++y])
	{
		x = -1;
		while (hold->map[y][++x])
		{
			if (!hold->pos_x && ft_is_valid_player_dir(hold->map[y][x]))
			{
				if (ft_value_pos(hold, ft_point(x, y)) == ERR)
					return (ERR);
			}
			else if (hold->pos_x && (ft_is_valid_player_dir(hold->map[y][x])))
				return (ft_error("Multiple players identified"));
		}
	}
	if (!hold->pos_x)
		return (ft_error("No player identified"));
	hold->map_w = x;
	hold->map_h = y;
	return (0);
}
