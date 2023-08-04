/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_2d_map(t_hold *hold)
{
	debug("ft_init_2D_map");
	hold->ppu = MAX_2D_LEN / ft_max(hold->map_w, hold->map_h);
	while (hold->ppu % 2)
		hold->ppu--;
	if (hold->ppu < 10)
		hold->ppu = 10;
	hold->pix_x = 0;
	hold->pix_y = 0;
	if (!hold->pix_x)
		hold->pix_x = START_2D_X + ft_to_pxl(hold, hold->pos_x)
			+ (hold->ppu / 2);
	if (!hold->pix_y)
		hold->pix_y = START_2D_Y + ft_to_pxl(hold, hold->pos_y)
			+ (hold->ppu / 2);
	hold->pl_map.x = hold->pos_x;
	hold->pl_map.y = hold->pos_y;
	hold->pl_w.x = (float)hold->pos_x + 0.5;
	hold->pl_w.y = (float)hold->pos_y + 0.5;
	ft_memset(hold->hit, 0, sizeof(int) * 5 * WIN_WIDTH);
	return (0);
}

int	ft_init(t_hold *hold)
{
	if (ft_init_map_pt(hold) == ERR)
		return (ERR);
	if (ft_init_2d_map(hold) == ERR)
		return (ERR);
	if (ft_init_holder(hold) == ERR)
		return (ERR);
	if (ft_init_mlx_win_img(hold) == ERR)
		return (ERR);
	if (ft_init_files(hold) == ERR)
		return (ERR);
	return (0);
}

int	ft_init_holder(t_hold *hold)
{
	hold->w_width = WIN_WIDTH;
	hold->w_height = WIN_HEIGHT;
	hold->w_name = ft_strdup(NAME);
	hold->img = (t_img *) malloc(sizeof(t_img));
	if (!hold->img)
		return (ft_error("failure: malloc - init holder img"));
	hold->img->img = 0;
	hold->img->addr = NULL;
	hold->img->bits_per_pixel = 0;
	hold->img->line_length = 0;
	hold->img->endian = 10;
	hold->tex = (t_tex **) malloc(sizeof(t_tex *) * 4);
	if (!hold->tex)
		return (ft_error("failure: malloc - init holder tex"));
	ft_memset(hold->tex, 0, sizeof(t_tex *) * 4);
	hold->tex_sprite = (t_tex **) malloc(sizeof(t_tex *) * 6);
	if (!hold->tex_sprite)
		return (ft_error("failure: malloc - init holder tex"));
	ft_memset(hold->tex_sprite, 0, sizeof(t_tex *) * 6);
	hold->game_level = LEVEL_MANDATORY;
	hold->f_game_over = 0;
	hold->counter_sprite = 0;
	hold->afplay_pid = 0;
	return (0);
}

int	ft_init_mlx_win_img(t_hold *h)
{
	int	temp[3];

	h->mlx = mlx_init();
	if (!h->mlx)
		return (ft_error("failure: mlx_init"));
	h->win = mlx_new_window(h->mlx, h->w_width, h->w_height, h->w_name);
	if (!h->win)
		return (ft_error("failure: mlx_new_window"));
	h->img->img = mlx_new_image(h->mlx, h->w_width, h->w_height);
	if (!h->img->img)
		return (ft_error("failure: mlx_new_image"));
	h->img->addr = mlx_get_data_addr(h->img->img, &temp[0], &temp[1], &temp[2]);
	h->img->bits_per_pixel = temp[0];
	h->img->line_length = temp[1];
	h->img->endian = temp[2];
	mlx_put_image_to_window(h->mlx, h->win, h->img->img, 0, 0);
	return (0);
}

float	ft_init_angle_direction(int c)
{
	float	angle;

	angle = ERR;
	if (c == 'E')
		angle = ft_angle_reset_radian(M_2PI - 0);
	else if (c == 'N')
		angle = ft_angle_reset_radian(M_2PI - M_PI_2);
	else if (c == 'W')
		angle = ft_angle_reset_radian(M_2PI - M_PI);
	else if (c == 'S')
		angle = ft_angle_reset_radian(M_2PI - (3 * M_PI_2));
	else
		return (ft_error("ft_angle_direction"));
	return (angle);
}
