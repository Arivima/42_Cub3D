/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <avilla-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:21:06 by avilla-m          #+#    #+#             */
/*   Updated: 2023/08/04 21:45:00 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_hold *hold, int status)
{
	debug("ft_exit");
	ft_putstr_fd("-----------------------------------------------------\n", 1);
	ft_putstr_fd("Exit.\n", 1);
	if (ft_free_at_exit(hold) == ERR)
		status = EXIT_FAILURE;
	if (status == EXIT_SUCCESS)
		ft_putstr_fd("\n>> Program exited successfully\n", 1);
	else if (status == EXIT_FAILURE)
		ft_putstr_fd("\n>> Program failed\n", 1);
	else
		ft_putstr_fd("\n>> Program exited successfully\n", 1);
	char *str = ft_strjoin("kill aplay ", ft_itoa(hold->afplay_pid));
	system(str);
	ft_putstr_fd("-----------------------------------------------------\n", 1);
	exit(status);
	return (status);
}

// free map, free all allocated stuff, close mlx
int	ft_free_at_exit(t_hold *hold)
{
	debug("ft_free_at_exit");
	if (!hold)
		return (ft_error("ft_free_at_exit"));
	if (hold->img && hold->img->img)
		mlx_destroy_image(hold->mlx, hold->img->img);
	if (hold->win)
		mlx_destroy_window(hold->mlx, hold->win);
	if (hold->w_name)
		free(hold->w_name);
	return (0);
}

int	ft_free(void *obj)
{
	debug("ft_free");
	free(obj);
	ft_memset(obj, '\0', sizeof(obj));
	return (0);
}
