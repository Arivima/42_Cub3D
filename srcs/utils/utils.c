/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:07:24 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:07:29 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	debug(char *str)
{
	if (DEBUG)
	{
		write(2, "\033[0;33mdebug: ", 14);
		write(2, str, ft_strlen(str));
		write(2, "\n\033[0m", 5);
	}
}

int	ft_isnumber(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != 0)
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	ft_parse_color(char *str)
{
	char	**matrix;
	int		ret;
	int		r;
	int		g;
	int		b;

	ret = ERR;
	if (str == NULL)
		return (ret);
	matrix = ft_split(str, ',');
	if (matrix == NULL)
		return (ft_error("Error in ft_split in parse_color"));
	if (ft_arr_cols(matrix) == 3 && ft_isnumber(matrix[0])
		&& ft_isnumber(matrix[1]) && ft_isnumber(matrix[2]))
	{
		r = ft_atoi(matrix[0]);
		g = ft_atoi(matrix[1]);
		b = ft_atoi(matrix[2]);
		if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
			ret = ft_trgb(0, r, g, b);
	}
	ft_arr_free(matrix);
	return (ret);
}

int	ft_is_line_empty(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		debug("stringa non allocata");
		return (1);
	}
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
			return (0);
		i++;
	}
	debug("ft_is_empty_line: empty line");
	return (1);
}

void	ft_add_new_string_to_list(t_vlist **lst, char *str)
{
	t_vlist	*new;

	new = ft_vlstnew(str);
	ft_vlstadd_back(lst, new);
}
