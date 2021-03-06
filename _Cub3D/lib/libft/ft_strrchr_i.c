/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:56:54 by avilla-m          #+#    #+#             */
/*   Updated: 2021/10/22 17:09:20 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_i(const char *s, int c)
{
	int		n;

	n = ft_strlen(s);
	while (n)
	{
		if (s[n] == (char)c)
			return (n);
		n--;
	}
	if (s[n] == (char)c)
		return (n);
	return (0);
}
