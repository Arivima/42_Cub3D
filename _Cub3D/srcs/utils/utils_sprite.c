/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vlist	*ft_new_sprite(t_pt_d pos, int type)
{
	t_vlist		*ret;
	t_sprite	*new;

	new = malloc(sizeof(*new));
	if (new == 0)
		return (0);
	new->x = pos.x;
	new->y = pos.y;
	new->dis = 0;
	new->type = type;
	if (type == ENEMY)
		new->n_spr = 0;
	if (type == SPRITE)
		new->n_spr = 1;
	ret = ft_vlstnew(new);
	return (ret);
}

int	ft_check_enemy_coll(t_hold *hold)
{
	t_pt		pos;
	t_pt_d		pos_sprite;
	t_vlist		*node;

	hold->sprite_list = 0;
	pos.y = 0;
	while (hold->map[pos.y])
	{
		pos.x = 0;
		while (hold->map[pos.y][pos.x])
		{
			if (hold->map[pos.y][pos.x] == ENEMY
				|| hold->map[pos.y][pos.x] == SPRITE)
			{
				pos_sprite.x = pos.x + 0.5;
				pos_sprite.y = pos.y + 0.5;
				node = ft_new_sprite(pos_sprite, hold->map[pos.y][pos.x]);
				ft_vlstadd_back(&hold->sprite_list, node);
			}
			++pos.x;
		}
		++pos.y;
	}
	return (0);
}
