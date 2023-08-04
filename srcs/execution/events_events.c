/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <avilla-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:14 by avilla-m          #+#    #+#             */
/*   Updated: 2023/08/04 21:45:00 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_event_bonus(t_hold *hold)
{
	debug("ft_event_bonus");
	hold->game_level++;
	if (hold->game_level == LEVEL_ENDING_LOST)
		hold->game_level = LEVEL_OPENING;
	else if (hold->game_level == LEVEL_ENDING_WIN)
		hold->game_level = LEVEL_CREDITS;
	if (hold->game_level == LEVEL_CREDITS + 1)
		hold->game_level = LEVEL_OPENING;
	ft_reset_world(hold);
	return (0);
}

static void	ft_upd_pos(t_hold *hold, t_pt_d w_pos)
{
	hold->pl_w.x = w_pos.x;
	hold->pl_w.y = w_pos.y;
	hold->pl_map.x = (int)hold->pl_w.x;
	hold->pl_map.y = (int)hold->pl_w.y;
	hold->pix_x = hold->pl_w.x * hold->ppu + START_2D_X;
	hold->pix_y = hold->pl_w.y * hold->ppu + START_2D_Y;
}

int	ft_move(t_hold *hold, int angle)
{
	t_pt_d	w_pos;
	int		position;

	debug("ft_move");
	w_pos.x = hold->pl_w.x + cos(hold->pos_a + ft_to_radian(angle));
	w_pos.y = hold->pl_w.y + sin(hold->pos_a + ft_to_radian(angle));
	position = hold->map[(int)w_pos.y][(int)w_pos.x];
	if (position == EMPTY || position == DOOR_OPEN || \
	position == SPRITE || position == ENEMY)
	{
		if (position == ENEMY)
		{
			hold->f_game_over = 1;
			hold->bonus_start = 1;
		}
		if (position == SPRITE)
		{
			system("aplay ./files/Light.mp3&");
			hold->counter_sprite++;
			hold->map[(int)w_pos.y][(int)w_pos.x] = EMPTY;
		}
		ft_upd_pos(hold, w_pos);
	}
	return (0);
}

int	ft_rotate(t_hold *hold, int direction)
{
	float	angle;

	debug("ft_rotate");
	hold->pos_a += direction * ROTATE_ANGLE;
	hold->pos_a = ft_angle_reset_radian(hold->pos_a);
	angle = 0;
	while (angle <= M_2PI)
	{
		if (!(hold->pos_a > ft_angle_reset_radian(angle + M_PI_64)) \
		&& !(hold->pos_a < ft_angle_reset_radian(angle - M_PI_64)))
			hold->pos_a = angle;
		angle += M_PI_2;
	}
	return (0);
}

int	ft_open_door_front(t_hold *hold)
{
	t_pt	pt;
	int		position;

	debug("ft_open_door_front");
	pt.x = hold->pix_x + roundf(hold->ppu * cos(hold->pos_a));
	pt.y = hold->pix_y + roundf(hold->ppu * sin(hold->pos_a));
	position = hold->map[ft_to_pt(hold, pt.y - START_2D_Y)] \
	[ft_to_pt(hold, pt.x - START_2D_X)];
	if (position == DOOR_CLOSED)
		hold->map[ft_to_pt(hold, pt.y - START_2D_Y)] \
		[ft_to_pt(hold, pt.x - START_2D_X)] = DOOR_OPEN;
	else if (position == DOOR_OPEN)
		hold->map[ft_to_pt(hold, pt.y - START_2D_Y)] \
		[ft_to_pt(hold, pt.x - START_2D_X)] = DOOR_CLOSED;
	return (0);
}
