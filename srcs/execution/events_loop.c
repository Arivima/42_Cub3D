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
	mlx_hook(hold->win, 4, 1L << 0, ft_get_mouse, hold);
	mlx_hook(hold->win, 17, 1L << 2, ft_exit, hold);
	mlx_hook(hold->win, 6, 1L << 0, ft_trasl, hold);
	mlx_hook(hold->win, 5, 1L << 0, ft_unlock, hold);
	mlx_loop_hook(hold->mlx, ft_render_gif, hold);
	ft_putstr_fd("\n>> Cub3D successfully executed !\n\n", 1);
	mlx_loop(hold->mlx);
	return (0);
}

int	ft_event(int keycode, t_hold *hold)
{
	debug("\n");
	debug("ft_event");
	if (keycode == KEYCODE_SPACE_BAR)
	{
		ft_event_bonus(hold);
		if (hold->bonus_start == 0)
			hold->afplay_pid = system("afplay ./files/Warabe_Uta.mp3&");
		hold->bonus_start = 1;
	}
	if (keycode == KEYCODE_ESC)
		ft_exit(hold, EXIT_SUCCESS);
	if (hold->pause_game == 0)
		ft_event_world(keycode, hold);
	ft_execution_bonus(hold);
	return (0);
}

int	ft_is_world(t_hold *hold)
{
	debug("ft_is_world");
	return ((hold->game_level == LEVEL_MANDATORY) \
	|| (hold->game_level == LEVEL_EARTH) \
	|| (hold->game_level == LEVEL_MOON));
}

int	ft_event_world(int keycode, t_hold *hold)
{
	debug("ft_event_world");
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
	return (0);
}
