/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:08:51 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:08:54 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	// for testing
	// test_line_star_color(env->img);
	// test_line_star(env->img);	
	// put_map(env->img, &env->map, env->draw, WHITE);
void	put_img(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->img);
	env->img->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!env->img->img)
		exit_fdf(env);
	env->img->addr = mlx_get_data_addr(env->img->img, \
	&env->img->bits_per_pixel, &env->img->line_length, &env->img->endian);
	put_map_color(env->img, &env->map, env->draw);
	put_display(env->img);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	put_menu_txt(env);
}

void	put_display(t_img *img)
{
	put_background(img, ft_point(MENU_X0, MENU_Y0), \
	ft_point(MENU_X1, MENU_Y1), BLACK);
	put_frame(img, ft_point(MENU_X0, MENU_Y0), \
	ft_point(MENU_X1, MENU_Y1), WHITE);
}

void	put_background(t_img *img, t_point a, t_point b, int color)
{
	int	i;

	i = 0;
	while ((a.y + i) <= b.y)
	{
		ft_line_bresenham(img, ft_point(a.x, a.y + i), \
		ft_point(b.x, a.y + i), color);
		i++;
	}
}

void	put_frame(t_img *img, t_point a, t_point b, int color)
{
	ft_line_bresenham(img, a, ft_point(b.x, a.y), color);
	ft_line_bresenham(img, a, ft_point(a.x, b.y), color);
	ft_line_bresenham(img, b, ft_point(b.x, a.y), color);
	ft_line_bresenham(img, b, ft_point(a.x, b.y), color);
}

void	put_menu_txt(t_env *mlx)
{
	int		nb_rows;
	int		gap;
	int		i;
	char	**s;

	s = ft_split(MENU_TXT, '\n');
	nb_rows = ft_arr_rows(s);
	gap = MENU_HEIGHT / nb_rows;
	i = 0;
	while (i < nb_rows && s[i])
	{
		mlx_string_put(mlx->mlx, mlx->win, MENU_X0 + MARGIN / 2, \
			MENU_Y0 + MARGIN / 2 + i * gap, MENU_COLOR, s[i]);
		i++;
	}
	free_split(s);
}
