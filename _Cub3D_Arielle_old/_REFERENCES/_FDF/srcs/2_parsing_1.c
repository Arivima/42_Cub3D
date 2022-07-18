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

t_map	**parse(char *file_name, int *height, int *width)
{
	t_map	**map;

	get_mapdim(file_name, height, width);
	map = map_create(file_name, *height, *width);
	return (map);
}

int	word_counter(const char *line, const char chr)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (line[i])
	{
		if (line[i] == chr)
			i++;
		else
		{
			word_counter++;
			while (line[i] != '\0' && line[i] != chr)
				i++;
		}
	}
	return (word_counter);
}

void	get_mapdim(char *file_name, int *height, int *width)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Impossible to open the specific file\n");
		exit(0);
	}
	get_next_line(fd, &line);
	*width = word_counter(line, ' ');
	(*height)++;
	free(line);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		(*height)++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
}
