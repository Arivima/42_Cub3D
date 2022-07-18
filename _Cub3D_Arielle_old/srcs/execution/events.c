/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:14 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:16 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_set_mlx_loop(t_hold *hold)
{
	debug("ft_set_mlx_loop");
	mlx_hook(hold->win, 2, 1L << 0, ft_event, hold);
	mlx_hook(hold->win, 17, 1L << 2, ft_exit, hold);
	printf("\n>> Cub3D successfully executed !\n\n");
	mlx_loop(hold->mlx);
	return (0);
}

int	ft_is_world(t_hold *hold)
{
	debug("ft_is_world");
	return ((hold->game_level == LEVEL_MANDATORY) \
	|| (hold->game_level == LEVEL_EARTH) \
	|| (hold->game_level == LEVEL_MOON));
}

	// add enemy sprites doors etc
int	ft_reset_world(t_hold *hold)
{
	debug("ft_reset_world");
	hold->pix_x = START_2D_X + ft_to_pxl(hold, hold->pos_x) + (hold->ppu / 2);
	hold->pix_y = START_2D_Y + ft_to_pxl(hold, hold->pos_y) + (hold->ppu / 2);
	hold->pos_a = ft_angle_reset_radian(M_2PI - M_PI);
	return (0);
}

int	ft_event_bonus(t_hold *hold)
{
	hold->game_level++;
	printf("new\tgame->level %d\n", hold->game_level);
	if (hold->game_level == LEVEL_CREDITS + 1)
		hold->game_level = LEVEL_OPENING;
	if (hold->game_level == LEVEL_EARTH)
		ft_reset_world(hold);
	return (0);
}

int	ft_event_world(int keycode, t_hold *hold)
{
	if (keycode == KEYCODE_CAM_LEFT)
		ft_rotate(hold, ROTATE_LEFT);
	else if (keycode == KEYCODE_CAM_RIGHT)
		ft_rotate(hold, ROTATE_RIGHT);
	else if (keycode == KEYCODE_LEFT)
		ft_move(hold, MOVE_LEFTWARD);
	else if (keycode == KEYCODE_RIGHT)
		ft_move(hold, MOVE_RIGHTWARD);
	else if (keycode == KEYCODE_DOWN)
		ft_move(hold, MOVE_BACKWARD);
	else if (keycode == KEYCODE_UP)
		ft_move(hold, MOVE_FORWARD);
	else if (keycode == KEYCODE_ENTER)
		ft_open_door_front(hold);
	else if (keycode == KEYCODE_SPACE_BAR)
		ft_event_bonus(hold);
	return (0);
}

int	ft_event(int keycode, t_hold *hold)
{
	debug("ft_event");
	printf("\nkeycode %d\n", keycode);
	printf("current\tgame->level %d\n", hold->game_level);
	if (keycode == KEYCODE_ESC)
		ft_exit(hold, EXIT_SUCCESS);
	if (ft_is_world(hold))
		ft_event_world(keycode, hold);
	else if (!ft_is_world(hold))
	{
		if (keycode == KEYCODE_SPACE_BAR)
			ft_event_bonus(hold);
	}
	if (keycode == KEYCODE_SPACE_BAR)
		ft_execution_bonus(hold);
	else
		ft_execution(hold);
	return (0);
}

int	ft_move(t_hold *hold, int angle)
{
	t_point	pt;
	int		position;

	pt.x = hold->pix_x + roundf(hold->ppu * \
	cos(hold->pos_a + ft_to_radian(angle)));
	pt.y = hold->pix_y + roundf(hold->ppu * \
	sin(hold->pos_a + ft_to_radian(angle)));
	position = hold->map[ft_to_pt(hold, pt.y - START_2D_Y)] \
	[ft_to_pt(hold, pt.x - START_2D_X)];
	if (position == EMPTY || position == DOOR_OPEN \
	|| position == SPRITE || position == ENEMY)
	{
		if (position == SPRITE)
		{
			// hold->counter_sprite++; // play music
			position = EMPTY;
		}
		if (position == ENEMY)
			hold->f_game_over = 1;
		hold->pix_x = pt.x;
		hold->pix_y = pt.y;
	}
	return (0);
}


int	ft_rotate(t_hold *hold, int direction)
{
	float	angle;

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
	t_point	pt;
	int		position;

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
