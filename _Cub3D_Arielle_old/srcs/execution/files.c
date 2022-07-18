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
	ft_open_all_files(hold);
	ft_open_texture(hold, hold->no, NO);
	ft_open_texture(hold, hold->so, SO);
	ft_open_texture(hold, hold->ea, EA);
	ft_open_texture(hold, hold->we, WE);
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
	hold->pics = (t_tex **) malloc(sizeof(t_tex *) * i);
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
	ft_free(pic_list);
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

int	ft_put_picture(t_hold *hold, int picture_id, t_point pix)
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

int	ft_put_gif(t_hold *hold, int frame_start, int frame_next)
{
	int	frame;
	int	i;
	int	frame_nb;

	debug("ft_put_gif");
	frame_nb = 20;
	if (ft_mlx_put_new_img(hold) == ERR)
		return (ERR);
	i = -1;
	while (++i < frame_nb)
	{
		frame = frame_start;
		while (frame < frame_next)
		{
			if (ft_put_picture(hold, frame, ft_point(0, 0)) == ERR)
				return (ERR);
			ft_put_text(hold);
			frame++;
		}
	}
	return (0);
}
