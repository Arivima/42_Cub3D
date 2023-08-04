/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(int ac, char **av, t_hold *hold)
{
	t_vlist	*preparse;
	int		ret;

	ft_memset(hold, '\0', sizeof(t_hold));
	if (check_arg(ac, av, hold) == ERR)
		return (ERR);
	if (init_holder(hold) == ERR)
		return (ERR);
	debug("ft() parsing textures and colors and checking validity of input");
	ret = ft_parse_arguments(hold);
	if (ret == ERR)
		return (ERR);
	debug("ft() preparsing to a list of strings and checking validity of map");
	preparse = NULL;
	ret = ft_preparse_map(hold, &preparse);
	if (ret == ERR)
		return (ERR);
	debug("ft() final parsing phase with malloc into an array");
	ret = ft_parse_map(hold, preparse);
	ft_vlstclear(&preparse, free);
	if (ret == ERR)
		return (ERR);
	ret = 0;
	return (ft_check_map(hold));
}

int	ft_check_file_validity(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (extension == NULL)
	{
		ft_error("Bad input. Only .cub file admitted (found none).");
		return (0);
	}
	if (ft_strncmp(extension, ".cub", 4))
	{
		ft_error("Bad input. Only .cub file admitted (wrong extension).");
		debug(extension);
		return (0);
	}
	return (1);
}

int	check_arg(int ac, char **av, t_hold *hold)
{
	if (ac < 2)
		return (ft_error("Bad input. No file specified"));
	else if (ac == 2)
	{
		if (av && hold)
		{
			debug("open fd and check for file validity");
			if (!ft_check_file_validity(av[1]))
				return (ERR);
			hold->fd = open(av[1], O_RDONLY);
			if (hold->fd == ERR)
			{
				perror("Bad input. File is invalid");
				return (ERR);
			}
		}
	}
	else if (ac > 3)
		return (ft_error("Bad input. Too many arguments"));
	return (0);
}

int	init_holder(t_hold *hold)
{
	hold->no = NULL;
	hold->so = NULL;
	hold->we = NULL;
	hold->ea = NULL;
	hold->ceiling = -1;
	hold->floor = -1;
	hold->dir[NO][0] = -1;
	hold->dir[NO][1] = 0;
	hold->dir[SO][0] = 1;
	hold->dir[SO][1] = 0;
	hold->dir[WE][0] = 0;
	hold->dir[WE][1] = -1;
	hold->dir[EA][0] = 0;
	hold->dir[EA][1] = 1;
	return (0);
}

int	is_valid_path(char *path)
{
	if (close(open(path, O_RDONLY) == ERR))
		return (ft_error("Bad input. Invalid path for texture"));
	return (0);
}
