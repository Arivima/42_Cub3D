/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw_shapes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:20:09 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:20:11 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	ft_draw_circle(t_hold *hold, t_point pt, int r, int color)
{
	double	i, angle, x1, y1;
	int	quarter, n;
	quarter =  (int)ft_to_degree(hold->pos_a);
	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		if (color != FLAG)
		{
			ft_line_bresenham_color(hold->img, ft_point(pt.x, pt.y), ft_point(pt.x + x1, pt.y + y1), ft_get_opposite_color(color));
			ft_mlx_pixel_put(hold->img, pt.x + x1, pt.y + y1, color);
		}
		else
		{
			ft_mlx_pixel_put(hold->img, pt.x + x1, pt.y + y1, RED);
			n = (int) angle - quarter;
			if (n < 0)
				n += 360;
			if (n > 360)
				n -= 360;
			if (n == 0  || n == 90 || n == 180  || n == 270 || n == 360)
				ft_line_bresenham_color(hold->img, ft_point(pt.x, pt.y), ft_point(pt.x + x1, pt.y + y1), RED);
		}
		i += 0.1;
	}
}

void	ft_draw_triangle(t_hold *hold, int x, int y, int r, int color)
{
	int xa, ya, xb, xc, yb, yc;
	xa = r / 2 * cos(ft_angle_reset_radian(hold->pos_a));
	ya = r / 2 * sin(ft_angle_reset_radian(hold->pos_a));
	xb = r / 2 * cos(ft_angle_reset_radian(hold->pos_a + 3 * M_PI / 4));
	yb = r / 2 * sin(ft_angle_reset_radian(hold->pos_a + 3 * M_PI / 4));
	xc = r / 2 * cos(ft_angle_reset_radian(hold->pos_a + 5 * M_PI / 4));
	yc = r / 2 * sin(ft_angle_reset_radian(hold->pos_a + 5 * M_PI / 4));


	ft_line_bresenham_color(hold->img, ft_point(x, y), ft_point(x + xa, y + ya), color);
	ft_line_bresenham_color(hold->img, ft_point(x + xa, y + ya), ft_point(x + xb, y + yb), color);
	ft_line_bresenham_color(hold->img, ft_point(x + xa, y + ya), ft_point(x + xc, y + yc), color);
	ft_line_bresenham_color(hold->img, ft_point(x + xb, y + yb), ft_point(x + xc, y + yc), color);

}

void	ft_draw_square(t_img *img, int x, int y, int r, int color)
{
	debug("ft_draw_square");
	ft_line_bresenham_color(img, ft_point(x, y), ft_point(x + r, y), color);
	ft_line_bresenham_color(img, ft_point(x, y), ft_point(x, y + r), color);
	ft_line_bresenham_color(img, ft_point(x + r, y), ft_point(x + r, y + r), color);
	ft_line_bresenham_color(img, ft_point(x, y + r), ft_point(x + r, y + r), color);
	ft_mlx_pixel_put(img, x + r, y + r, color);
}
