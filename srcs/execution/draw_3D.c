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
	int		wall_height;
	int		draw_start;
	int		draw_end;

	debug("   ft_put_walls");
	max = (float)sqrt(pow(WIN_WIDTH * (hold->map_w - 2), 2) + \
	pow(WIN_WIDTH * (hold->map_h - 2), 2));
	i = -1;
	while (++i < WIN_WIDTH)
	{
		wall_height = (int) MAX_3D_WALL / hold->hit[DIS][i];
		draw_start = -wall_height / 2 + MAX_3D_WALL / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = wall_height / 2 + MAX_3D_WALL / 2;
		if (draw_end >= MAX_3D_WALL)
			draw_end = MAX_3D_WALL;
		if (ft_get_wall_texture(hold, i) != 0)
			ft_line_tex(hold, i, ft_point(draw_start, draw_end), \
			ft_get_wall_texture(hold, i));
	}
	return (0);
}

static void	ft_prepare_floor(t_hold *hold)
{	
	t_tex	*tex;
	char	*path;

	if (hold->game_level == LEVEL_EARTH)
		path = "files/floor_earth.xpm";
	else
		path = "files/floor_moon.xpm";
	tex = malloc(sizeof(t_tex));
	if (hold->game_level == LEVEL_EARTH)
		tex->img = mlx_xpm_file_to_image(hold->mlx, path, &tex->w, &tex->h);
	else
		tex->img = mlx_xpm_file_to_image(hold->mlx, path, &tex->w, &tex->h);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bp, &tex->sl, &tex->en);
	ft_floor_cast(hold, tex);
	free(tex);
}

int	ft_put_background_bonus(t_hold *hold)
{
	char	*path;
	int		w;
	int		h;

	w = 0;
	h = 0;
	if (hold->game_level == LEVEL_EARTH)
		path = "files/background_earth.xpm";
	else
		path = "files/background_moon.xpm";
	hold->img->img = mlx_xpm_file_to_image(hold->mlx, path, &w, &h);
	if (!hold->img->img)
		return (ft_error("ft_open_picture: mlx_xpm_file_to_image"));
	hold->img->addr = mlx_get_data_addr(hold->img->img, \
	&hold->img->bits_per_pixel, &hold->img->line_length, &hold->img->endian);
	if (!hold->img->addr)
		return (ft_error("ft_open_picture: mlx_xpm_file_to_image"));
	ft_prepare_floor(hold);
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
	if (hold->game_level == LEVEL_MANDATORY)
	{
		if (ft_put_background_mandatory(hold) == ERR)
			return (ERR);
	}
	else if (hold->game_level == LEVEL_EARTH
		|| hold->game_level == LEVEL_MOON)
	{
		if (ft_put_background_bonus(hold) == ERR)
			return (ERR);
	}
	return (0);
}
