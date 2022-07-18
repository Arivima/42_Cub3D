/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:20:53 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:20:55 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

int	ft_error( char *msg)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd("\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n", 2);
	return (ERR);
}

char	*ft_error_null(char *msg)
{
	ft_error(msg);
	return (NULL);
}
