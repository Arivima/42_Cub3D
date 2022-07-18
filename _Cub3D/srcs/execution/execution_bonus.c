/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:24 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:25 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_exe_level(t_hold *hold)
{
	debug("ft_exe_level");
	if (hold->game_level == LEVEL_OPENING)
		ft_level_opening(hold);
	else if (hold->game_level == LEVEL_EARTH)
		ft_level_earth(hold);
	else if (hold->game_level == LEVEL_TRANSITION)
		ft_level_transition(hold);
	else if (hold->game_level == LEVEL_MOON)
		ft_level_moon(hold);
	else if (hold->game_level == LEVEL_ENDING_LOST)
		ft_level_ending_lost(hold);
	else if (hold->game_level == LEVEL_ENDING_WIN)
		ft_level_ending_win(hold);
	else if (hold->game_level == LEVEL_CREDITS)
		ft_level_credits(hold);
	else if (hold->game_level == LEVEL_MANDATORY)
		ft_execution(hold);
	else
		return (ft_error("ft_execution_bonus"));
	return (0);
}

int	ft_execution_bonus(t_hold *hold)
{
	debug("ft_execution_bonus");
	if (hold->counter_sprite == 5 && hold->game_level == LEVEL_EARTH)
		hold->game_level = LEVEL_TRANSITION;
	else if (hold->counter_sprite == 5 && hold->game_level == LEVEL_MOON)
		hold->game_level = LEVEL_ENDING_WIN;
	else if (hold->counter_sprite == 5)
	{
		hold->pause_game = 1;
		if (ft_put_picture(hold, e_PIC_WIN_00, ft_point(0, 0)) == ERR)
			return (ERR);
		return (0);
	}
	if (hold->f_game_over && hold->game_level != LEVEL_MANDATORY)
		hold->game_level = LEVEL_ENDING_LOST;
	else if (hold->f_game_over)
	{
		hold->pause_game = 1;
		if (ft_put_picture(hold, e_PIC_LOST_00, ft_point(0, 0)) == ERR)
			return (ERR);
		return (0);
	}
	if (hold->f_game_over == 1 || hold->counter_sprite == 5)
		ft_reset_world(hold);
	return (ft_exe_level(hold));
}

int	ft_level_earth(t_hold *hold)
{
	debug("ft_level_earth");
	hold->pause_game = 0;
	if (ft_put_world(hold) == ERR)
		return (ERR);
	return (0);
}

int	ft_level_moon(t_hold *hold)
{
	hold->pause_game = 0;
	debug("ft_level_moon");
	if (ft_put_world(hold) == ERR)
		return (ERR);
	return (0);
}
