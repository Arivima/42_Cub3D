/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:19:03 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:19:05 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_open_texture(t_hold *hold, char *path, int type)
{
	debug("ft_open_texture");
	t_tex	*tx;

	tx = hold->tex[type];
	if (tx == 0)
	{
		tx = (t_tex *) malloc(sizeof(t_tex));
		{
			tx->img = mlx_xpm_file_to_image(hold->mlx, path, &tx->w, &tx->h);
			tx->addr = mlx_get_data_addr(tx->img, &tx->bp, &tx->sl, &tx->en);
			tx->charged = 1;
		}
		hold->tex[type] = tx;
	}
}

int	ft_get_tex_color(t_point pt, t_tex *tex)
{
	unsigned int	pt_tex;
	unsigned char	rgb[3];

	pt_tex = pt.y * tex->sl + tex->bp / 8 * pt.x;
	rgb[0] = (unsigned char)tex->addr[pt_tex + 2];
	rgb[1] = (unsigned char)tex->addr[pt_tex + 1];
	rgb[2] = (unsigned char)tex->addr[pt_tex];
	return ((int)rgb[0] << 16 | (int)rgb[1] << 8 | (int)rgb[2]);
}

t_tex	*ft_get_wall_texture(t_hold *hold, int i)
{
	// debug("ft_get_wall_texture");
	t_tex	*tex;

	tex = 0;
	if (hold->game_level == LEVEL_MOON)
		tex = hold->pics[e_PIC_FLOOR_EARTH];
	else if (hold->game_level == LEVEL_EARTH)
		tex = hold->pics[e_PIC_FLOOR_MOON];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_north)
		tex = hold->tex[SO];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_south)
		tex = hold->tex[NO];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_east)
		tex = hold->tex[WE];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_west)
		tex = hold->tex[EA];
	return (tex);
}

void	ft_line_bresenham_tex(t_hold *hold, int idx, int wall_height, t_tex *tex)
{
	// debug("ft_line_bresenham_tex");
	int start;
	int end;
	double wallX;
	double step;
	t_point tex_p;
	float	angle_unit;
	float	start_angle;
	float	angle;

	if (tex == 0)
		return;
	// calcolate where the line starts and ends
	start = -wall_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = wall_height / 2 + WIN_HEIGHT / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;

	angle_unit = (float)FOV / (float)WIN_WIDTH;
	start_angle = hold->pos_a - (FOV / 2);
	angle = hold->pos_a - (start_angle + (idx * angle_unit));
	// we calculate the x of the texture for the line	
	// printf("p p: %d %d dist: %d\n", hold->pix_x, hold->pix_y, hold->hit[DIS][idx]);
	t_point box;
	box.x = ft_to_pt(hold, hold->hit[IX][idx] - START_2D_X) * WIN_WIDTH;
	box.y = ft_to_pt(hold, hold->hit[IY][idx] - START_2D_Y) * WIN_WIDTH;
	int distance;
	if (hold->hit[WALL_ORIENTATION][idx] == e_wall_north || hold->hit[WALL_ORIENTATION][idx] == e_wall_south)
	{
		distance = hold->hit[MX][idx] - box.x;
		tex_p.x = (distance * 100 / WIN_WIDTH);
	}
	if (hold->hit[WALL_ORIENTATION][idx] == e_wall_east || hold->hit[WALL_ORIENTATION][idx] == e_wall_west)
	{
		distance = hold->hit[MY][idx] - box.y;
		tex_p.x = (distance * 100 / WIN_WIDTH);
	}
	// if (hold->hit[WALL_ORIENTATION][idx] == e_wall_north || hold->hit[WALL_ORIENTATION][idx] == e_wall_south)
	// 	wallX = hold->pix_y + hold->hit[DIS][idx] * sin(angle);
	// else
	// 	wallX = hold->pix_x + hold->hit[DIS][idx] * cos(angle);
	// printf("BEFORE %f\n", wallX);
	// tex_p.x -= floor((tex_p.x)); // ?
	// printf("AFTER %f\n", wallX);
	// // printf("wallX: %f\n", wallX);
	tex_p.x = (int)(tex_p.x * tex->w / 100);
	// printf("tex.x: %d\n", tex_p.x);
	step = 1.0 * tex->h / wall_height;
	wallX = (start - WIN_HEIGHT / 2 + wall_height / 2) * step;
	// printf("wall_height: %d wallY: %f\n", wall_height, wallX);
	while (start != end)
	{
		tex_p.y = ((int)wallX) & (tex->h - 1);
		wallX += step;
		start += 1;
		if (hold->hit[DOOR][idx])
			ft_mlx_pixel_put(hold->img, idx, start, ft_get_opposite_color(ft_get_tex_color(tex_p, tex)));
		else
			ft_mlx_pixel_put(hold->img, idx, start, ft_get_tex_color(tex_p, tex));

	}
	// printf("wall_height: %d wallY: %f\n", wall_height, wallX);
}
