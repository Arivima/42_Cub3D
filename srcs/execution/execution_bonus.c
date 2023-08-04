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

int	ft_execution_bonus(t_hold *hold)
{
	debug("ft_execution_bonus");
	if (hold->f_game_over)
		hold->game_level = LEVEL_ENDING_LOST;
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
	else
		return (ft_error("ft_execution_bonus"));
	return (0);
}

int	ft_level_opening(t_hold *hold)
{
	debug("ft_level_opening");
	if (ft_put_gif(hold, e_PIC_ANIMATION_00_00, e_PIC_ANIMATION_01_00) == ERR)
		return (ERR);
	return (0);
}

int	ft_level_transition(t_hold *hold)
{
	debug("ft_level_transition");
	if (ft_put_gif(hold, e_PIC_ANIMATION_01_00, e_PIC_ANIMATION_02_00) == ERR)
		return (ERR);
	// music
	return (0);
}

int	ft_level_ending_lost(t_hold *hold)
{
	debug("ft_level_ending_lost");
	
	if (ft_put_gif(hold, e_PIC_ANIMATION_02_00, e_PIC_ANIMATION_03_00))
		return (ERR);
	// music
	return (0);
}

int	ft_level_ending_win(t_hold *hold)
{
	debug("ft_level_ending_win");
	if (ft_put_gif(hold, e_PIC_ANIMATION_03_00, e_PIC_ANIMATION_04_00))
		return (ERR);
	// music
	return (0);
}

int	ft_level_credits(t_hold *hold)
{
	debug("ft_level_credits");
	if (ft_put_gif(hold, e_PIC_ANIMATION_04_00, e_PIC_ANIMATION_05_00))
		return (ERR);
	// music
	return (0);
}

int	ft_level_earth(t_hold *hold)
{
	debug("ft_level_earth");

	if (ft_put_world(hold) == ERR)
		return (ERR);	

	// // music
	// if (ft_put_picture(hold, e_PIC_PLAYER, ft_point(hold->pix_x  - hold->pics[e_PIC_PLAYER]->w / 2, hold->pix_y - hold->pics[e_PIC_PLAYER]->h / 2)) == ERR)
	// 	return (ERR);
	return (0);
}

int	ft_level_moon(t_hold *hold)
{
	debug("ft_level_moon");
	if (ft_put_world(hold) == ERR)
		return (ERR);
	// music
	if (ft_put_picture(hold, e_PIC_PLAYER, ft_point(hold->pix_x  - hold->pics[e_PIC_PLAYER]->w / 2, hold->pix_y - hold->pics[e_PIC_PLAYER]->h / 2)) == ERR)
		return (ERR);
	return (0);
}
