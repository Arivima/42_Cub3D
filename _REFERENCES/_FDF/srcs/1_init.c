/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:58 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:08:02 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx_and_img(t_env *env)
{
	init(env);
	env->mlx = mlx_init();
	if (!env->mlx)
		exit_fdf(env);
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!env->win)
		exit_fdf(env);
	env->img->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!env->img->img)
		exit_fdf(env);
	env->img->addr = mlx_get_data_addr(env->img->img, &env->img->\
	bits_per_pixel, &env->img->line_length, &env->img->endian);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

void	init(t_env *env)
{
	env->mlx = 0;
	env->win = 0;
	env->img = (t_img *) malloc(sizeof(t_img));
	env->img->img = 0;
	env->img->addr = NULL;
	env->img->bits_per_pixel = 0;
	env->img->line_length = 0;
	env->img->endian = 10;
	env->draw = (t_draw *) malloc(sizeof(t_draw));
	env->draw->height = 0;
	env->draw->width = 0;
	env->draw->map_diag = 0;
	env->draw->scale_width = 0;
	env->draw->scale_height = 0;
	env->draw->scale = 0;
	env->draw->map_width = 0;
	env->draw->map_height = 0;
	env->draw->map_hypothenuse = 0;
	env->draw->angle = 0;
	env->draw->projection = 1;
}

void	reset_to_default(t_env *env)
{
	env->draw->angle = ISOMETRIC;
	env->draw->scale = ft_min(env->draw->scale_width, env->draw->scale_height);
}

void	update_settings(t_env *env)
{
	env->draw->angle = ISOMETRIC;
	env->draw->map_diag = ft_abs((sqrt(\
	pow(env->draw->height, 2) + pow(env->draw->width, 2))));
	env->draw->scale_width = ((ZONE_WIDTH / env->draw->map_diag));
	env->draw->scale_height = ((ZONE_HEIGHT / env->draw->map_diag));
	env->draw->scale = ft_min(env->draw->scale_width, env->draw->scale_height);
	env->draw->map_width = (env->draw->width * env->draw->scale);
	env->draw->map_height = (env->draw->height * env->draw->scale);
	env->draw->map_hypothenuse = \
	ft_abs((sqrt(pow(env->draw->map_height, 2) \
	+ pow(env->draw->map_width, 2))));
}
	// for testing
// ft_printf("\n\nIn function update_settings
//--------\n\n"); print_env(env, env->img);