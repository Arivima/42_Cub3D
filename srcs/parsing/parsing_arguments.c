/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_arg_is_full(t_hold *h)
{
	if (h->no == NULL || h->so == NULL || h->we == NULL || h->ea == NULL)
		return (0);
	if (h->ceiling == -1 || h->floor == -1)
		return (0);
	return (1);
}

static int	ft_parse_texture(t_hold *hold, char **matrix)
{
	if (!matrix)
		return (ft_error("ft_parse_textures: no input"));
	if (is_valid_path(matrix[1]) == ERR)
		return (ft_error("ft_parse_texture: not a valid path"));
	if (!hold->no && !ft_strncmp(matrix[0], "NO", 3))
		hold->no = ft_strdup(matrix[1]);
	else if (!hold->so && !ft_strncmp(matrix[0], "SO", 2))
		hold->so = ft_strdup(matrix[1]);
	else if (!hold->we && !ft_strncmp(matrix[0], "WE", 2))
		hold->we = ft_strdup(matrix[1]);
	else if (!hold->ea && !ft_strncmp(matrix[0], "EA", 2))
		hold->ea = ft_strdup(matrix[1]);
	else
		return (ft_error("Bad input. Duplicate path for texture"));
	return (0);
}

static int	ft_parse_colors(t_hold *hold, char **matrix)
{
	if (!matrix)
		return (ft_error("ft_parse_colors: no input"));
	if (hold->ceiling == -1 && !ft_strncmp(matrix[0], "C", 2))
		hold->ceiling = ft_parse_color(matrix[1]);
	else if (hold->floor == -1 && !ft_strncmp(matrix[0], "F", 2))
		hold->floor = ft_parse_color(matrix[1]);
	else
		return (ft_error("Bad input. Duplicate path for colors."));
	return (0);
}

static int	ft_parse_arg_line(t_hold *hold, char *buffer)
{
	char	**mtx;
	int		ret;

	ret = -1;
	if (buffer == NULL)
		return (ERR);
	mtx = ft_split(buffer, ' ');
	if (mtx == NULL)
		return (ft_error("Error in ft_parse_arg_line: split"));
	if (ft_arr_cols(mtx) != 2)
		ft_error("Error in ft_parse_arg_line: too many arguments");
	else
	{
		if (!ft_strncmp(mtx[0], "NO", 3) || !ft_strncmp(mtx[0], "SO", 3)
			|| !ft_strncmp(mtx[0], "WE", 3) || !ft_strncmp(mtx[0], "EA", 3))
			ret = ft_parse_texture(hold, mtx);
		else if (!ft_strncmp(mtx[0], "F", 2) || !ft_strncmp(mtx[0], "C", 2))
			ret = ft_parse_colors(hold, mtx);
		else
			ret = ft_error("Error in ft_parse_arg_line: wrong identifier");
	}
	ft_arr_free(mtx);
	return (ret);
}

int	ft_parse_arguments(t_hold *hold)
{
	int		arg_ended;
	char	*buffer;
	int		ret;

	arg_ended = 1;
	while (arg_ended)
	{
		ret = get_next_line(hold->fd, &buffer);
		if (ret > 0 && !ft_is_line_empty(buffer))
			ret = ft_parse_arg_line(hold, buffer);
		free(buffer);
		if (ret == ERR)
			return (ERR);
		if (ret == 0 && ft_arg_is_full(hold))
			arg_ended = 0;
	}
	return (0);
}
