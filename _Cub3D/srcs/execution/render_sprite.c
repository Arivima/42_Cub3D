/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:17:47 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:17:49 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_ren2(t_render *r)
{
	r->sprite_size.y = (int)(WIN_HEIGHT / r->trasf.y);
	if (r->sprite_size.y < 0)
		r->sprite_size.y *= -1;
	r->draw_start.y = -r->sprite_size.y / 2 + WIN_HEIGHT / 2;
	if (r->draw_start.y < 0)
		r->draw_start.y = 0;
	r->draw_end.y = r->sprite_size.y / 2 + WIN_HEIGHT / 2;
	if (r->draw_end.y >= WIN_HEIGHT)
		r->draw_end.y = WIN_HEIGHT - 1;
}

static void	ft_ren3(t_render *r)
{
	if (r->sprite_size.x < 0)
		r->sprite_size.x *= -1;
	r->draw_start.x = -r->sprite_size.x / 2 + r->sprite_screen.x;
	if (r->draw_start.x < 0)
		r->draw_start.x = 0;
	r->draw_end.x = r->sprite_size.x / 2 + r->sprite_screen.x;
	if (r->draw_end.x >= WIN_WIDTH)
		r->draw_end.x = WIN_WIDTH - 1;
}

static void	ft_ren_loop2(t_hold *hold, t_render *r, int i, t_pt tex_pos)
{
	int	j;
	int	temp;
	int	d;
	int	color;

	j = r->draw_start.y;
	while (j < r->draw_end.y)
	{
		d = j * 256 - WIN_HEIGHT * 128 + r->sprite_size.y * 128;
		temp = (d * hold->tex_sprite[(hold->game_level) + (r->sprite->n_spr)]->h);
		// temp = (d * hold->tex_sprite[r->sprite->n_spr]->h);
		tex_pos.y = (temp / r->sprite_size.y) / 256;
		color = ft_get_tex_color(tex_pos, hold->tex_sprite[(hold->game_level) + (r->sprite->n_spr)]);
		// color = ft_get_tex_color(tex_pos, hold->tex_sprite[r->sprite->n_spr]);
		if (color != BLACK)
			ft_mlx_pixel_put(hold->img, i, j, color);
		++j;
	}
}

static void	ft_ren_loop(t_hold *hold, t_render *r, t_sprite *sprite)
{
	int		i;
	int		temp;
	t_pt	tex_pos;

	i = r->draw_start.x;
	while (i < r->draw_end.x)
	{
		r->sprite = sprite;
		temp = 256 * (i - (r->sprite_screen.x - r->sprite_size.x / 2));
		temp *= hold->tex_sprite[(hold->game_level) + (sprite->n_spr)]->w;
		// temp *= hold->tex_sprite[sprite->n_spr]->w;
		tex_pos.x = (int)(temp / r->sprite_size.x) / 256;
		if (r->trasf.y > 0 && i > 0 && i < WIN_WIDTH
			&& r->trasf.y < hold->hit[DIS][i])
			ft_ren_loop2(hold, r, i, tex_pos);
		++i;
	}
}

int	ft_render_sprite(t_hold *hold, t_sprite *sprite)
{
	t_render	r;

	if (hold->map[(int)sprite->y][(int)sprite->x] == EMPTY)
		return (0);
	r.trasf = ft_ren_start(hold, sprite);
	r.sprite_screen.x = (int)((WIN_WIDTH / 2) * (1 + r.trasf.x / r.trasf.y));
	ft_ren2(&r);
	r.sprite_size.x = (int)(WIN_HEIGHT / r.trasf.y);
	ft_ren3(&r);
	ft_ren_loop(hold, &r, sprite);
	return (0);
}
