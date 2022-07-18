/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:53 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:56 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_calc_delta_dist(t_ray *ray)
{
	if (ray->ray_dir.x == 0)
		ray->delta_dist.x = 1e10;
	else
		ray->delta_dist.x = 1 / ray->ray_dir.x;
	if (ray->delta_dist.x < 0)
		ray->delta_dist.x *= -1;
	if (ray->ray_dir.y == 0)
		ray->delta_dist.y = 1e10;
	else
		ray->delta_dist.y = 1 / ray->ray_dir.y;
	if (ray->delta_dist.y < 0)
		ray->delta_dist.y *= -1;
}

static void	ft_calc_step(t_hold *hold, int idx, t_ray *ray)
{
	if (hold->hit[IX][idx] < 0)
		ray->step.x = -1;
	else
		ray->step.x = 1;
	if (hold->hit[IY][idx] < 0)
		ray->step.y = -1;
	else
		ray->step.y = 1;
}

static void	ft_calc_side_dist(t_pt_d pos, t_pt map, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = (pos.x - map.x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (map.x - pos.x + 1.0) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = (pos.y - map.y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (map.y - pos.y + 1.0) * ray->delta_dist.y;
}

static void	ft_calc_hit(t_hold *hold, int idx, t_ray *ray, t_pt	*map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			map->x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			map->y += ray->step.y;
			ray->side = 1;
		}
		if (hold->map[map->y][map->x] == WALL
			|| hold->map[map->y][map->x] == DOOR_CLOSED)
			hit = 1;
	}
	if (hold->map[map->y][map->x] == DOOR_CLOSED)
		hold->hit[DOOR][idx] = 1;
}

int	ft_line_hit(t_hold *hold, t_pt_d pos, t_pt map, int idx)
{
	t_ray	ray;

	ray.ray_dir.x = hold->hit[IX][idx];
	ray.ray_dir.y = hold->hit[IY][idx];
	ft_calc_delta_dist(&ray);
	ft_calc_step(hold, idx, &ray);
	ft_calc_side_dist(pos, map, &ray);
	ft_calc_hit(hold, idx, &ray, &map);
	if (ray.side == 0)
	{
		hold->hit[DIS][idx] = (ray.side_dist.x - ray.delta_dist.x);
		if (map.x > hold->pl_map.x)
			hold->hit[WALL_ORIENTATION][idx] = e_wall_east;
		else
			hold->hit[WALL_ORIENTATION][idx] = e_wall_west;
	}
	else
	{
		hold->hit[DIS][idx] = (ray.side_dist.y - ray.delta_dist.y);
		if (map.y > hold->pl_map.y)
			hold->hit[WALL_ORIENTATION][idx] = e_wall_south;
		else
			hold->hit[WALL_ORIENTATION][idx] = e_wall_north;
	}
	return (0);
}
