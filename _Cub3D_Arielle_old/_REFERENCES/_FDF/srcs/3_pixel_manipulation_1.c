/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_pixel_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:08:36 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:08:38 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// for testing
// ft_printf("\n\nIn function init_pixels-----
//---\n\n");test_print_map(tmp, draw);
void	init_pixels(t_map ***map, t_draw *draw)
{
	t_map	**tmp;

	tmp = *map;
	update_pixels(&tmp, draw, &projection);
	draw->offset = ft_distance(map, draw);
	update_pixels(&tmp, draw, &align_to_display);
}

void	update_pixels(t_map ***map, t_draw *draw, \
void (*f)(t_map ***, int, int, t_draw *))
{
	t_map	**tmp;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			f(&tmp, x, y, draw);
			x++;
		}
		y++;
	}
}

// includes scaling
void	projection(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	tmp = *map;
	tmp[y][x].pix_x = ((x - y) * cos(draw->angle)) * draw->scale;
	tmp[y][x].pix_y = ((x + y) * sin(draw->angle) - tmp[y][x].z) * draw->scale;
}

// currently aligned to top left angle of draw zone
void	align_to_display(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	tmp = *map;
	tmp[y][x].pix_x += ZONE_X0 + draw->offset.x;
	tmp[y][x].pix_y += ZONE_Y0 + draw->offset.y;
}
