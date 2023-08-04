/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:14 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:16 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_trasl(int x, int y, t_hold *hold)
{
	int		dist;
	float	ratio;
	t_pt	end;

	if (hold->pause_game == 0 && hold->mouse_block == 1)
	{
		end = ft_point(x, y);
		dist = hold->mouse_start.x - end.x;
		ratio = ((float)dist * 1.5) / (float)WIN_WIDTH;
		ratio *= FOV_D;
		hold->pos_a += ft_to_radian(ratio);
		hold->mouse_start = end;
		ft_execution(hold);
	}
	return (0);
}

int	ft_unlock(int button, int x, int y, t_hold *hold)
{
	int		dist;
	float	ratio;
	t_pt	end;

	if (hold->pause_game == 0 && button == 2)
	{
		end = ft_point(x, y);
		hold->mouse_block = 0;
		dist = hold->mouse_start.x - end.x;
		ratio = ((float)dist * 1.5) / (float)WIN_WIDTH;
		ratio *= FOV_D;
		hold->pos_a += ft_to_radian(ratio);
		ft_execution(hold);
	}
	return (0);
}

int	ft_get_mouse(int button, int x, int y, t_hold *hold)
{
	if (hold->pause_game == 0 && button == 2)
	{
		hold->mouse_block = 1;
		hold->mouse_start = ft_point(x, y);
	}
	return (0);
}
