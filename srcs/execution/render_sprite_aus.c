/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:17:47 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:17:49 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_pt_d	ft_ren_start(t_hold *hold, t_sprite *sprite)
{
	t_pt_d		dir;
	t_pt_d		plane;
	t_pt_d		trasf;
	t_pt_d		sprite_pos;
	float		inv_det;

	dir.x = cos(hold->pos_a);
	dir.y = sin(hold->pos_a);
	plane.x = cos(hold->pos_a + M_PI_2) * FOV_R;
	plane.y = sin(hold->pos_a + M_PI_2) * FOV_R;
	sprite_pos.x = sprite->x - hold->pl_w.x;
	sprite_pos.y = sprite->y - hold->pl_w.y;
	inv_det = 1.0 / (plane.x * dir.y - dir.x * plane.y);
	trasf.x = inv_det * (dir.y * sprite_pos.x - dir.x * sprite_pos.y);
	trasf.y = inv_det * (-plane.y * sprite_pos.x + plane.x * sprite_pos.y);
	return (trasf);
}
