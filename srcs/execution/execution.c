/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:32 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:35 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_execution(t_hold *hold)
{
	debug("ft_execution");
	if (ft_put_world(hold) == ERR)
		return (ERR);
	return (0);
}
	// if (hold->counter_sprite == 5)
	// {
	// 	hold->game_level++;
	// 	hold->counter_sprite = 0;
	// 	return (ft_execution_bonus(hold));
	// }

int	ft_put_world(t_hold *hold)
{
	if (ft_mlx_put_new_img(hold) == ERR)
		return (ERR);
	if (ft_put_display(hold) == ERR)
		return (ERR);
	mlx_put_image_to_window(hold->mlx, hold->win, hold->img->img, 0, 0);
	ft_put_text(hold);
	if (ft_put_picture(hold, e_PIC_PLAYER, \
	ft_point(hold->pix_x - hold->pics[e_PIC_PLAYER]->w / 2, \
	hold->pix_y - hold->pics[e_PIC_PLAYER]->h / 2)) == ERR)
		return (ERR);
	return (0);
}
	// if (ft_put_sprites(hold) == ERR)
	// 	return (ERR);
	// if (ft_put_enemy(hold) == ERR)
	// 	return (ERR);
	// if (ft_put_player_2D(hold) == ERR)
	// 	return (ERR); // see below, just to clean

int	ft_mlx_put_new_img(t_hold *hold)
{
	debug(" ft_mlx_put_new_img");
	if (hold->mlx && hold->img && hold->img->img)
		mlx_destroy_image(hold->mlx, hold->img->img);
	else
		return (ft_error("ft_mlx_put_new_img"));
	ft_memset(hold->img, '\0', sizeof(t_img));
	hold->img->img = mlx_new_image(hold->mlx, hold->w_width, hold->w_height);
	if (!hold->img->img)
		return (ft_error("failure: mlx_new_image"));
	hold->img->addr = NULL;
	hold->img->addr = mlx_get_data_addr(hold->img->img, \
	&hold->img->bits_per_pixel, &hold->img->line_length, &hold->img->endian);
	if (!hold->img->addr)
		return (ft_error("failure: mlx_get_data_addr"));
	return (0);
}

int	ft_put_display(t_hold *hold)
{
	debug("  ft_put_display");
	if (ft_raycasting(hold) == ERR
		|| ft_put_background(hold) == ERR
		|| ft_put_walls(hold) == ERR
		|| ft_put_2dmap(hold) == ERR)
		return (ERR);
	return (0);
}

int	ft_put_text(t_hold *hold)
{
	int		i;
	char	**level;
	char	**s;
	int		y;
	int		color;

	debug("ft_put_text");
	level = ft_split(LEVEL_TEXT, '#');
	s = ft_split(level[hold->game_level], '\n');
	color = ft_get_opposite_color(ft_get_img_color(hold->img, \
	ft_point(TEXT_START_X, TEXT_START_Y)));
	if (!color)
		color = COLOR_TEXT;
	i = -1;
	y = TEXT_START_Y;
	while (s[++i])
	{
		mlx_string_put(hold->mlx, hold->win, TEXT_START_X, y, color, s[i]);
		y += 20;
	}
	ft_arr_free(level);
	ft_arr_free(s);
	return (0);
}
