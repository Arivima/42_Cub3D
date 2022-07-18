/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:18:43 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:18:45 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_render_gif(t_hold *hold)
{
	if (hold->pause_game == 1 && hold->gif_block == 1 && hold->gif_frame == 0)
	{
		if (ft_mlx_put_new_img(hold) == ERR)
			return (ERR);
		if (ft_put_picture(hold, hold->git_iter, ft_point(0, 0)) == ERR)
			return (ERR);
		ft_put_text(hold);
		hold->git_iter++;
		if (hold->git_iter >= hold->gif_end)
			hold->git_iter = hold->gif_start;
	}
	hold->gif_frame++;
	if (hold->gif_frame == 1000)
		hold->gif_frame = 0;
	return (0);
}

int	ft_put_gif(t_hold *hold, int frame_start, int frame_next)
{
	debug("ft_put_gif");
	hold->gif_block = 1;
	hold->gif_start = frame_start;
	hold->gif_end = frame_next;
	hold->git_iter = frame_start;
	hold->gif_frame = 0;
	return (0);
}
