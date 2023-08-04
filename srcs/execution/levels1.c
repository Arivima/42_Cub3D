/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:24 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:25 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_level_opening(t_hold *hold)
{
	debug("ft_level_opening");
	hold->pause_game = 1;
	if (ft_put_gif(hold, e_PIC_ANIMATION_00_00, e_PIC_ANIMATION_01_00) == ERR)
		return (ERR);
	return (0);
}

int	ft_level_transition(t_hold *hold)
{
	debug("ft_level_transition");
	hold->pause_game = 1;
	if (ft_put_gif(hold, e_PIC_ANIMATION_01_00, e_PIC_ANIMATION_02_00) == ERR)
		return (ERR);
	return (0);
}

int	ft_level_ending_lost(t_hold *hold)
{
	debug("ft_level_ending_lost");
	hold->pause_game = 1;
	if (ft_put_gif(hold, e_PIC_ANIMATION_02_00, e_PIC_ANIMATION_03_00))
		return (ERR);
	return (0);
}

int	ft_level_ending_win(t_hold *hold)
{
	debug("ft_level_ending_win");
	hold->pause_game = 1;
	if (ft_put_gif(hold, e_PIC_ANIMATION_03_00, e_PIC_ANIMATION_04_00))
		return (ERR);
	return (0);
}

int	ft_level_credits(t_hold *hold)
{
	debug("ft_level_credits");
	hold->pause_game = 1;
	if (ft_put_gif(hold, e_PIC_ANIMATION_04_00, e_PIC_ANIMATION_05_00))
		return (ERR);
	return (0);
}
