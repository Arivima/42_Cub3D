/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:17:47 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:17:49 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_put_walls(t_hold *hold)
{
	int		i;
	float	max;
	float	ai;
	float	ratio;
	int		wall_height;
	int		y0;

	debug("   ft_put_walls");
	max = (float)sqrt(pow(WIN_WIDTH * (hold->map_w - 2), 2) + \
	pow(WIN_WIDTH * (hold->map_h - 2), 2));
	i = -1;
	while (++i < WIN_WIDTH)
	{
		ai = (float)(hold->hit[DIS][i]);
		ratio = (ai / max);
		if (ratio >= 1)
			ratio = 0.999999;
		if (ratio <= 0)
			ratio = 0.000001;
		wall_height = (int)((1 - ratio) * MAX_3D_WALL);
		y0 =  (WIN_HEIGHT - wall_height) / 2;
		// if (ft_get_wall_texture(hold, i) != 0)
		// 	ft_line_bresenham_tex(hold, i, wall_height, \
		// 	ft_get_wall_texture(hold, i));
		ft_line_bresenham_color(hold->img, ft_point(i, y0),
		ft_point(i, y0 + wall_height), ft_get_wall_color(hold, i));
	}
	return (0);
}


int	ft_put_background_bonus(t_hold *hold)
{
	char	*path;
	int		w;
	int		h;

	w = 0;
	h = 0;
	if (hold->game_level == LEVEL_EARTH)
		path = "files/animation_01.xpm";
	else
		path = "files/animation_01.xpm";
	hold->img->img = mlx_xpm_file_to_image(hold->mlx, path, &w, &h);
	if (!hold->img->img)
		return (ft_error("ft_open_picture: mlx_xpm_file_to_image"));
	hold->img->addr = mlx_get_data_addr(hold->img->img, \
	&hold->img->bits_per_pixel, &hold->img->line_length, &hold->img->endian);
	if (!hold->img->addr)
		return (ft_error("ft_open_picture: mlx_xpm_file_to_image"));
	return (0);
}

int	ft_put_background_mandatory(t_hold *hold)
{
	int	i;

	i = -1;
	while (++i < hold->w_height / 2)
	{
		if (hold->game_level == LEVEL_MOON)
			ft_line_bresenham_color(hold->img, ft_point(0, i), \
			ft_point(hold->w_width, i), ft_get_opposite_color(hold->ceiling));
		else
			ft_line_bresenham_color(hold->img, ft_point(0, i), \
			ft_point(hold->w_width, i), hold->ceiling);
	}
	while (++i <= hold->w_height)
	{
		if (hold->game_level == LEVEL_MOON)
			ft_line_bresenham_color(hold->img, ft_point(0, i), \
			ft_point(hold->w_width, i), ft_get_opposite_color(hold->floor));
		else
			ft_line_bresenham_color(hold->img, ft_point(0, i), \
			ft_point(hold->w_width, i), hold->floor);
	}
	return (0);
}

int	ft_put_background(t_hold *hold)
{
	debug("   ft_put_background");
	if (ft_put_background_mandatory(hold) == ERR)
		return (ERR);
	return (0);
}

	// if (hold->game_level == LEVEL_MANDATORY)
	// {
		// if (ft_put_background_mandatory(hold) == ERR)
		// 	return (ERR);
	// }
	// else if (hold->game_level == LEVEL_EARTH 
	// || hold->game_level == LEVEL_MOON)
	// {
	// 	if (ft_put_background_bonus(hold) == ERR)
	// 		return (ERR);
	// }