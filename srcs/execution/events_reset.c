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

int	ft_reset_world(t_hold *hold)
{
	debug("ft_reset_world");
	hold->pix_x = START_2D_X + ft_to_pxl(hold, hold->pos_x) + (hold->ppu / 2);
	hold->pix_y = START_2D_Y + ft_to_pxl(hold, hold->pos_y) + (hold->ppu / 2);
	hold->pl_map.x = hold->pos_x;
	hold->pl_map.y = hold->pos_y;
	hold->pl_w.x = hold->pos_x + 0.5;
	hold->pl_w.y = hold->pos_y + 0.5;
	hold->pos_a = ft_angle_reset_radian(M_2PI - M_PI);
	hold->map = ft_array_cpy(hold->storedmap);
	hold->counter_sprite = 0;
	hold->f_game_over = 0;
	return (0);
}
