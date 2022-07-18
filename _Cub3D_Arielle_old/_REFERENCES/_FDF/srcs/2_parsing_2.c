/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:08:11 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:08:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **l_split)
{
	int	w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}

void	put_value(t_map *row, char *line)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_split(line, ' ');
	while (split[j])
	{
		row[j].z = ft_atoi_base(split[j], 10);
		row[j].pix_x = 0;
		row[j].pix_y = 0;
		if (!ft_strchr(split[j], ','))
			row[j].color = COLOR_INIT;
		else
			row[j].color = ft_atoi_base(ft_strchr(split[j], ',') + 3, 16);
		j++;
	}
	free_split(split);
}

t_map	**map_alloc(int height, int width)
{
	t_map	**map;
	int		i;

	i = 0;
	map = (t_map **)malloc(sizeof(t_map *) * height);
	while (i < height)
		map[i++] = (t_map *)malloc(sizeof(t_map) * width);
	return (map);
}

t_map	**map_create(char *file_name, int height, int width)
{
	int		i;
	t_map	**map;
	char	*line;
	int		fd;

	i = 0;
	line = NULL;
	map = map_alloc(height, width);
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		put_value(map[i], line);
		i++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
	return (map);
}
