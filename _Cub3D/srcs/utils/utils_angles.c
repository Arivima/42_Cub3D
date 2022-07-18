/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_angles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	ft_to_radian(float angle)
{
	float	ret;

	ret = angle * M_PI / 180;
	return (roundf(ret * 1000000) / 1000000);
}

float	ft_to_degree(float angle)
{
	float	ret;

	ret = angle / M_PI * 180;
	return (roundf(ret * 1000000) / 1000000);
}

float	ft_angle_reset_radian(float angle)
{
	if (angle >= M_2PI)
		angle -= M_2PI;
	if (angle < 0)
		angle += M_2PI;
	return (angle);
}

float	ft_angle_reset_degree(float angle)
{
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (360 - angle);
}
