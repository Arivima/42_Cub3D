/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <avilla-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:19:03 by avilla-m          #+#    #+#             */
/*   Updated: 2023/08/04 21:42:50 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open_texture(t_hold *hold, char *path, int type)
{
	t_tex	*tx;

	debug("ft_open_texture");
	if (!path)
		return (ERR);
	tx = hold->tex[type];
	if (tx == 0)
	{
		tx = (t_tex *) malloc(sizeof(t_tex));
		{
			tx->img = mlx_xpm_file_to_image(hold->mlx, path, &tx->w, &tx->h);
			if (!tx->img)
				return (ERR);
			tx->addr = mlx_get_data_addr(tx->img, &tx->bp, &tx->sl, &tx->en);
			tx->charged = 1;
			if (!tx->addr)
				return (ERR);
		}
		hold->tex[type] = tx;
	}
	return (0);
}

int	ft_get_tex_color(t_pt pt, t_tex *tex)
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
	t_tex	*tex;

	tex = 0;
	if (hold->game_level == LEVEL_MOON)
		tex = hold->pics[e_PIC_WALL_MOON];
	else if (hold->game_level == LEVEL_EARTH)
		tex = hold->pics[e_PIC_WALL_EARTH];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_north)
		tex = hold->tex[SO];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_south)
		tex = hold->tex[NO];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_east)
		tex = hold->tex[WE];
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_west)
		tex = hold->tex[EA];
	if (hold->game_level == LEVEL_MOON && hold->hit[DOOR][i])
		tex = hold->pics[e_PIC_DOOR_MOON];
	else if (hold->game_level == LEVEL_EARTH && hold->hit[DOOR][i])
		tex = hold->pics[e_PIC_DOOR_EARTH];
	else if (hold->hit[DOOR][i])
		tex = hold->pics[e_PIC_DOOR_00];
	return (tex);
}

int	ft_calc_wall_x(t_hold *hold, int idx, t_tex *tex)
{
	float	temp;
	int		ret;

	if (hold->hit[WALL_ORIENTATION][idx] == e_wall_east \
	|| hold->hit[WALL_ORIENTATION][idx] == e_wall_west)
		temp = hold->pl_w.y + (hold->hit[DIS][idx] * hold->hit[IY][idx]);
	else
		temp = hold->pl_w.x + (hold->hit[DIS][idx] * hold->hit[IX][idx]);
	temp -= floor((temp));
	ret = (int)(temp * (float)tex->w);
	if (hold->hit[WALL_ORIENTATION][idx] == e_wall_east \
	|| hold->hit[WALL_ORIENTATION][idx] == e_wall_west)
	{
		if (hold->hit[IX][0] > 0) //!
			ret = tex->w - ret - 1;
	}
	else
	{
		if (hold->hit[IY][0] < 0) //!
			ret = tex->w - ret - 1;
	}
	return (ret);
}

void	ft_line_tex(t_hold *hold, int idx, t_pt wall, t_tex *tex)
{
	float	temp;
	float	step;
	int		wall_height;
	t_pt	wall_pt;

	if (tex == 0)
		return ;
	wall_pt.x = ft_calc_wall_x(hold, idx, tex);
	wall_height = wall.y - wall.x;
	step = (float)tex->h / (float)wall_height;
	temp = (wall.x - (WIN_HEIGHT / 2) + (wall_height / 2)) * step;
	while (wall.x < wall.y)
	{
		wall_pt.y = (int)temp;
		temp += step;
		wall.x += 1;
		if (hold->hit[DOOR][idx])
			ft_mlx_pixel_put(hold->img, idx, wall.x, \
			ft_get_tex_color(wall_pt, tex));
		else
			ft_mlx_pixel_put(hold->img, idx, wall.x, \
			ft_get_tex_color(wall_pt, tex));
	}
}
