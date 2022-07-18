/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:43 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:45 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_files(t_hold *hold)
{
	debug("ft_init_files");
	if ((ft_open_all_files(hold) == ERR) \
	|| ft_open_texture(hold, hold->no, NO) == ERR \
	|| ft_open_texture(hold, hold->so, SO) == ERR \
	|| ft_open_texture(hold, hold->ea, EA) == ERR \
	|| ft_open_texture(hold, hold->we, WE) == ERR \
	|| ft_open_sprite(hold, "files/Umbreon.xpm", 0) == ERR \
	|| ft_open_sprite(hold, "files/player_heart.xpm", 1) == ERR \
	|| ft_open_sprite(hold, "files/enemy_earth.xpm", 2) == ERR \
	|| ft_open_sprite(hold, "files/sprite_earth.xpm", 3) == ERR \
	|| ft_open_sprite(hold, "files/enemy_moon.xpm", 4) == ERR \
	|| ft_open_sprite(hold, "files/sprite_moon.xpm", 5) == ERR)
		return (ERR);
	return (0);
}

int	ft_open_all_files(t_hold *hold)
{
	char	**pic_list;
	int		i;

	debug("ft_open_all_files");
	pic_list = ft_split(IMG_FILES, '\n');
	i = 0;
	while (pic_list[i])
		i++;
	hold->pics = (t_tex **) malloc(sizeof(t_tex *) * (i + 1));
	if (!hold->pics)
		return (ft_error("ft_open_all_files: malloc"));
	ft_memset(hold->pics, '\0', sizeof(t_tex *));
	i = -1;
	while (pic_list[++i])
	{
		hold->pics[i] = (t_tex *) malloc(sizeof(t_tex));
		if (!hold->pics[i])
			return (ft_error("ft_open_all_files: malloc"));
		ft_memset(hold->pics[i], '\0', sizeof(t_tex));
		ft_open_picture(hold, pic_list[i], i);
	}
	hold->pics[i] = 0;
	ft_arr_free(pic_list);
	return (0);
}

int	ft_open_picture(t_hold *hold, char *path, int i)
{
	t_tex	*p;

	debug("ft_open_picture");
	p = hold->pics[i];
	if (p)
	{
		p->img = mlx_xpm_file_to_image(hold->mlx, path, &p->w, &p->h);
		if (!p->img)
			return (ft_error("ft_open_picture: mlx_xpm_file_to_image"));
		p->addr = mlx_get_data_addr(p->img, &p->bp, &p->sl, &p->en);
		if (!p->addr)
			return (ft_error("ft_open_picture: mlx_xpm_file_to_image"));
		p->charged = 1;
		hold->pics[i] = p;
	}
	return (0);
}

int	ft_put_picture(t_hold *hold, int picture_id, t_pt pix)
{
	t_tex	*p;

	debug("ft_put_picture");
	p = hold->pics[picture_id];
	if (p && p->charged && p->img)
		mlx_put_image_to_window(hold->mlx, hold->win, p->img, pix.x, pix.y);
	else
		return (ft_error("ft_put_picture: failed image upload"));
	return (0);
}
