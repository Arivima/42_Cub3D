/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_pixel_manipulation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:08:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:08:27 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_pixel(t_env *env)
{
	reset_to_default(env);
	init_pixels(&env->map, env->draw);
	put_img(env);
}

void	color_update(t_map ***map, int x, int y, t_draw *draw)
{	
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].color = get_opposite_color(tmp[y][x].color);
}

void	rotation(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;
	int		xi;
	int		yi;

	if (draw)
		;
	tmp = *map;
	xi = tmp[y][x].pix_x;
	yi = tmp[y][x].pix_y;
	tmp[y][x].pix_x = (int)((xi - ZONE_XC) * cos(ROTATION)) \
	- (int)((yi - ZONE_YC) * sin(ROTATION)) + ZONE_XC;
	tmp[y][x].pix_y = (int)((xi - ZONE_XC) * sin(ROTATION)) \
	+ (int)((yi - ZONE_YC) * cos(ROTATION)) + ZONE_YC;
}

void	change_projection(t_env *env)
{
	env->draw->projection++;
	if (env->draw->projection == 100)
		env->draw->projection = 0;
	if (env->draw->projection % 2)
		env->draw->angle = ISOMETRIC_2_1;
	else
		env->draw->angle = CAVALIER;
	init_pixels(&env->map, env->draw);
	put_img(env);
}
