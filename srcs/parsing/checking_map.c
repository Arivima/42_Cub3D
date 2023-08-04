/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_flag(t_hold *hold, int flag, t_point pt)
{
	if (flag == 0)
	{
		if (hold->map[pt.y][pt.x] == '0')
			return (-1);
		if (hold->map[pt.y][pt.x] == '1')
			return (1);
		return (0);
	}
	else if (flag == 1)
	{
		if (hold->map[pt.y][pt.x] == ' ')
			return (0);
		if (hold->map[pt.y][pt.x] == '0')
			return (2);
		return (1);
	}
	else if (flag == 2)
	{
		if (hold->map[pt.y][pt.x] == ' ')
			return (-1);
		if (hold->map[pt.y][pt.x] == '1')
			return (1);
		return (2);
	}
	return (-1);
}

static int	ft_check_map_row(t_hold *hold)
{
	t_point	pt;
	int		flag;

	pt = ft_point(0, 0);
	while (hold->map[pt.y])
	{
		flag = 0;
		while (hold->map[pt.y][pt.x] != 0)
		{
			flag = ft_check_flag(hold, flag, pt);
			if (flag == -1)
				return (-1);
			pt.x += 1;
		}
		if (flag == 2)
			return (-1);
		pt.y += 1;
		pt.x = 0;
	}
	return (0);
}

static int	ft_check_map_col(t_hold *hold)
{
	t_point	pt;
	int		flag;

	pt = ft_point(0, 0);
	while (hold->map[pt.y] && hold->map[pt.y][pt.x])
	{
		flag = 0;
		while (hold->map[pt.y] && hold->map[pt.y][pt.x])
		{
			flag = ft_check_flag(hold, flag, pt);
			if (flag == -1)
				return (-1);
			pt.y += 1;
		}
		if (flag == 2)
			return (-1);
		pt.x += 1;
		pt.y = 0;
	}
	return (0);
}

int	ft_check_first_row(t_hold *hold)
{
	int	x;

	x = 0;
	while (hold->map[0][x] && hold->map[0][x] != '1')
		x++;
	if (hold->map[0][x] == 0)
		return (ERR);
	return (0);
}

int	ft_check_map(t_hold *hold)
{
	if (ft_check_first_row(hold) == ERR)
		return (ft_error("ft_check_map: no wall in first line"));
	if (ft_check_map_row(hold) == ERR)
		return (ft_error("ft_check_map: error in rows"));
	if (ft_check_map_col(hold) == ERR)
		return (ft_error("ft_check_map: error in columns"));
	return (0);
}
