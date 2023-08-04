#include "cub3D.h"

int	ft_raycasting(t_hold *hold)
{
	debug("   ft_raycasting");
	int		i;
	float	angle;
	float	start_angle;
	float	angle_unit;
	t_point	start;
	t_point	end;

	ft_memset(hold->hit, 0, sizeof(int) * 8 * WIN_WIDTH);
	start.x = hold->pix_x;
	start.y = hold->pix_y;
	start_angle = hold->pos_a - (FOV / 2);
	angle_unit = (float)FOV / (float)WIN_WIDTH;
	i = -1;
	while (++i < WIN_WIDTH)
	{
		angle = start_angle + (i * angle_unit);
		hold->hit[HIT_ANGLE][i] = (int) 10000 * (angle);
		end.x = start.x +(hold->pix_H * cos(angle));
		end.y = start.y +(hold->pix_H * sin(angle));
		if (ft_line_bresenham_hit(hold, start, end, i) == ERR)
			return (ERR); 
	}
	i--;
	while (--i >= 0)
	{
		if ((hold->hit[WALL_ORIENTATION][i] == e_wall_angle) ||(hold->hit[WALL_ORIENTATION][i] == e_wall_other))
			hold->hit[WALL_ORIENTATION][i] = hold->hit[WALL_ORIENTATION][i + 1];
	}
	return (0);
}

int	ft_line_bresenham_hit(t_hold *hold, t_point a, t_point b, int j)
{
	t_bres	bres;
	t_point	i;

	i = a;
	bres.dx = ft_abs(b.x - i.x);
	bres.sx = ft_sign(i.x, b.x);
	bres.dy = -ft_abs(b.y - i.y);
	bres.sy = ft_sign(i.y, b.y);
	bres.err = bres.dx + bres.dy;
	while (i.x != b.x || i.y != b.y)
	{
		if (ft_is_point_on_map(hold, i, WALL) || ft_is_point_on_map(hold, i, DOOR_CLOSED))
			return (ft_store_hit_data(hold, a, i, j));
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.dy)
		{
			bres.err += bres.dy;
			i.x += bres.sx;
		}
		if (bres.e2 <= bres.dx)
		{
			bres.err += bres.dx;
			i.y += bres.sy;
		}
	}
	return (0);
}

int	ft_store_hit_data(t_hold *hold, t_point a, t_point i, int j)
{
	t_point player;
	t_point	hit_point;
	float	angle_unit;
	float	start_angle;
	float	angle;
	float	ai;

	player.x = ft_to_world_x(hold, a.x);
	player.y = ft_to_world_y(hold, a.y);
	hit_point.x = ft_to_world_x(hold, i.x);
	hit_point.y = ft_to_world_y(hold, i.y);
	hold->hit[IX][j] = i.x;
	hold->hit[IY][j] = i.y;
	hold->hit[MX][j] = hit_point.x;
	hold->hit[MY][j] = hit_point.y;
	angle_unit = (float)FOV / (float)WIN_WIDTH;
	start_angle = hold->pos_a - (FOV / 2);
	angle = hold->pos_a - (start_angle + (j * angle_unit));
	ai = sqrt(pow(ft_abs(player.x - hit_point.x), 2) + pow(ft_abs(player.y - hit_point.y), 2));
	hold->hit[DIS][j] = ai * cos(angle);
	if (ft_is_point_on_map(hold, i, DOOR_CLOSED))
		hold->hit[DOOR][j] = 1;
	if (ft_store_orientation(hold, i, j) == ERR)
		return (ERR);
	return (0);
}

int	ft_store_orientation(t_hold *hold, t_point i, int j)
{
	enum	e_wall_oriententation;
	t_point	n;
	t_point temp;
	int		max_pix;

	hold->hit[WALL_ORIENTATION][j] = 0;
	static int flag = 0;
	int color = -1;
	if (j != 0)
	{
		n.y = ft_to_pt(hold, i.y - START_2D_Y);
		n.x = ft_to_pt(hold, i.x - START_2D_X);
		temp.x = ft_to_pt(hold, hold->hit[IX][j - 1] - START_2D_X);
		temp.y = ft_to_pt(hold, hold->hit[IY][j - 1] - START_2D_Y);
		if (temp.x != n.x || temp.y != n.y)
		{
			hold->hit[WALL_ORIENTATION][j] = e_wall_angle;
			flag = 1;
			color = hold->hit[WALL_ORIENTATION][j - 1];
		}	
	}
	if (hold->hit[WALL_ORIENTATION][j] == 0)
	{
		n.x = (i.x - START_2D_X) % hold->ppu; 
		n.y = (i.y - START_2D_Y) % hold->ppu;
		max_pix = hold->ppu - 1;

		if ((n.x == 0) && !(n.y == 0) && !(n.y == max_pix))
		{
			hold->hit[WALL_ORIENTATION][j] = e_wall_west;
			flag = 0;
			return (0);
		}
		else if ((n.x == max_pix) && !(n.y == 0) && !(n.y == max_pix))
		{
			hold->hit[WALL_ORIENTATION][j] = e_wall_east;
			flag = 0;
			return (0);
		}
		else if ((n.y == 0) && !(n.x == 0) && !(n.x == max_pix))
		{
			hold->hit[WALL_ORIENTATION][j] = e_wall_north;
			flag = 0;
			return (0);
		}
		else if ((n.y == max_pix) && !(n.x == 0) && !(n.x == max_pix))
		{
			hold->hit[WALL_ORIENTATION][j] = e_wall_south;
			flag = 0;
			return (0);
		}
		else
		{
			if ((j != 0) && (flag == 0))
			{
				hold->hit[WALL_ORIENTATION][j] = hold->hit[WALL_ORIENTATION][j - 1];
			}
			else if ((j != 0) && (flag = 1) && hold->hit[WALL_ORIENTATION][j - 1])
			{
				hold->hit[WALL_ORIENTATION][j] = e_wall_other;
			}
			else
				hold->hit[WALL_ORIENTATION][j] = e_wall_angle;
		}
	}
	return (0);
}

int	ft_get_wall_color(t_hold *hold, int i)
{
	int color;
	color = BLACK;
	if (hold->hit[WALL_ORIENTATION][i] == e_wall_north)
		color = COLOR_WALL_SOUTH;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_south)
		color = COLOR_WALL_NORTH;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_east)
		color = COLOR_WALL_WEST;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_west)
		color = COLOR_WALL_EAST;
	else if (hold->hit[WALL_ORIENTATION][i] == e_wall_angle)
		color = COLOR_WALL_ANGLE;
	return (color);
}

// texture ol

// void	ft_line_bresenham_tex(t_hold *hold, int idx, int wall_height, t_tex *tex)
// {
// 	// debug("ft_line_bresenham_tex");
// 	int start;
// 	int end;
// 	double wallX;
// 	double step;
// 	t_point tex_p;
// 	float	angle_unit;
// 	float	start_angle;
// 	float	angle;

// 	if (tex == 0)
// 		return;
// 	start = -wall_height / 2 + WIN_HEIGHT / 2;
// 	if (start < 0)
// 		start = 0;
// 	end = wall_height / 2 + WIN_HEIGHT / 2;
// 	if (end >= WIN_HEIGHT)
// 		end = WIN_HEIGHT - 1;

// 	angle_unit = (float)FOV / (float)WIN_WIDTH;
// 	start_angle = hold->pos_a - (FOV / 2);
// 	angle = hold->pos_a - start_angle + ((float)idx * angle_unit);
	
// 	t_point box;
// 	box.x = ft_to_pt(hold, hold->hit[IX][idx] - START_2D_X) * WIN_WIDTH;
// 	box.y = ft_to_pt(hold, hold->hit[IY][idx] - START_2D_Y) * WIN_WIDTH;
// 	int distance;
// 	if (hold->hit[WALL_ORIENTATION][idx] == e_wall_north || hold->hit[WALL_ORIENTATION][idx] == e_wall_south)
// 	{
// 		distance = hold->hit[MX][idx] - box.x;
// 		tex_p.x = ((float)distance / (float)WIN_WIDTH) * (float)tex->w;
// 	}
// 	if (hold->hit[WALL_ORIENTATION][idx] == e_wall_east || hold->hit[WALL_ORIENTATION][idx] == e_wall_west)
// 	{
// 		distance = hold->hit[MY][idx] - box.y;
// 		tex_p.x = (distance * 100 / WIN_WIDTH);
// 	}
// 	tex_p.x = (int)(tex_p.x * tex->w / 100);
// 	step = 1.0 * tex->h / wall_height;
// 	wallX = (start - WIN_HEIGHT / 2 + wall_height / 2) * step;
// 	while (start != end)
// 	{
// 		tex_p.y = ((int)wallX) & (tex->h - 1);
// 		wallX += step;
// 		start += 1;
// 		if (hold->hit[DOOR][idx])
// 			ft_mlx_pixel_put(hold->img, idx, start, ft_get_opposite_color(ft_get_tex_color(tex_p, tex)));
// 		else
// 			ft_mlx_pixel_put(hold->img, idx, start, ft_get_tex_color(tex_p, tex));
// 	}
// }
