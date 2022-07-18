/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:34 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:09:36 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(t_env *env)
{
	if (env->map)
		map_free(env->map, env->draw->height);
	if (env->draw)
		free(env->draw);
	if (env->img)
		free(env->img);
	if (env->img->img)
		mlx_destroy_image(env->mlx, env->img->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

void	map_free(t_map **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}
