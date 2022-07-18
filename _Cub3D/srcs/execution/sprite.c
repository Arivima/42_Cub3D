/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:17:47 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:17:49 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open_sprite(t_hold *hold, char *path, int idx)
{
	t_tex	*s;

	debug("ft_open_sprite");
	s = hold->tex_sprite[idx];
	if (s == 0)
	{
		s = (t_tex *) malloc(sizeof(t_tex));
		{
			s->img = mlx_xpm_file_to_image(hold->mlx, path, &s->w, &s->h);
			if (!s->img)
				return (ERR);
			s->addr = mlx_get_data_addr(s->img, &s->bp, &s->sl, &s->en);
			if (!s->addr)
				return (ERR);
			s->charged = 1;
		}
		hold->tex_sprite[idx] = s;
	}
	return (0);
}

static t_sprite	*ft_calc_dis(t_hold *hold, t_sprite *item)
{
	t_pt_d		pos;

	pos.x = hold->pl_w.x - item->x;
	pos.y = hold->pl_w.y - item->y;
	item->dis = pos.x * pos.x + pos.y * pos.y;
	return (item);
}

static void	ft_pos_sorted(t_sprite **sorted, int i, t_sprite *item)
{
	int	j;
	int	k;
	int	ok;

	j = 0;
	ok = 0;
	while (j < i && ok == 0)
	{
		if (sorted[j]->dis < item->dis)
		{
			k = i;
			while (k > j)
			{
				sorted[k] = sorted[k - 1];
				k--;
			}
			sorted[k] = item;
			ok = 1;
		}
		++j;
	}
	if (ok == 0)
	sorted[i] = item;
}

t_sprite	**ft_sort_list(t_hold *hold)
{
	t_vlist		*iter;
	t_sprite	**sorted;
	t_sprite	*item;
	int			i;

	iter = hold->sprite_list;
	sorted = malloc(sizeof(t_sprite *) * ft_vlstsize(iter));
	if (sorted == NULL)
		return (NULL);
	ft_memset(sorted, 0, sizeof(t_sprite *) * ft_vlstsize(iter));
	i = 0;
	while (iter != NULL)
	{
		item = ft_calc_dis(hold, iter->content);
		if (i == 0)
			sorted[0] = item;
		else
			ft_pos_sorted(sorted, i, item);
		++i;
		iter = iter->next;
	}
	return (sorted);
}

int	ft_put_sprite(t_hold *hold)
{
	t_sprite	**sorted;
	int			i;
	int			j;

	sorted = ft_sort_list(hold);
	if (sorted == NULL)
		return (ERR);
	j = ft_vlstsize(hold->sprite_list);
	i = 0;
	while (i < j)
	{
		ft_render_sprite(hold, sorted[i]);
		++i;
	}
	free(sorted);
	return (0);
}
