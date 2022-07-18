/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_jump_newlines(t_hold *hold)
{
	int		ret;
	char	*buffer;

	ret = 1;
	buffer = NULL;
	while (ret == 1)
	{
		ret = get_next_line(hold->fd, &buffer);
		if (ret == 1 && ft_is_line_empty(buffer))
			free(buffer);
		else if (ret == ERR)
		{
			ft_error("ft_jump_newlines: error in get_next_line");
			return (buffer);
		}
		else
			ret = 0;
	}
	return (buffer);
}

int	ft_preparse_map(t_hold *hold, t_vlist **preparse)
{
	char	*buffer;
	int		ret;

	buffer = ft_jump_newlines(hold);
	if (buffer == NULL)
		return (ERR);
	ret = 1;
	while (ret == 1)
	{
		if (ft_is_line_empty(buffer))
		{
			if (buffer != NULL)
				free(buffer);
			ft_vlstclear(preparse, free);
			return (ft_error("ft_preparse_map: empty line in map"));
		}
		ft_add_new_string_to_list(preparse, buffer);
		ret = get_next_line(hold->fd, &buffer);
	}
	if (ret == 0 && !ft_is_line_empty(buffer))
		ft_add_new_string_to_list(preparse, buffer);
	return (0);
}

size_t	ft_max_lenght(t_vlist *vlist)
{
	size_t	ret;

	ret = 0;
	while (vlist != NULL)
	{
		if (ft_strlen((char *)(vlist->content)) > ret)
			ret = ft_strlen((char *)(vlist->content));
		vlist = vlist->next;
	}
	return (ret);
}

int	ft_parse_map(t_hold *hold, t_vlist *pre)
{
	size_t	cols;
	int		i;

	hold->map = malloc((ft_vlstsize(pre) + 1) * sizeof(int *));
	if (hold->map == NULL)
		return (ft_error("ft_parse_map: error in malloc"));
	hold->map[ft_vlstsize(pre)] = NULL;
	cols = ft_max_lenght(pre);
	i = 0;
	while (pre != NULL)
	{
		hold->map[i] = malloc(cols + 1);
		if (hold->map[i] == NULL)
		{
			ft_arr_free(hold->map);
			return (ft_error("ft_parse_map: error in malloc"));
		}
		ft_memset(hold->map[i], ' ', cols);
		hold->map[i][cols] = 0;
		ft_memcpy(hold->map[i++], pre->content, ft_strlen(pre->content));
		pre = pre->next;
	}
	hold->storedmap = ft_array_cpy(hold->map);
	return (0);
}
