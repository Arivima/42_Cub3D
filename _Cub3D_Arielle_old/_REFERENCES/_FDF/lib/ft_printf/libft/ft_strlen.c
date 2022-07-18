/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:53:51 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/21 18:08:40 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(const char *s)
{
	size_t	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

int	nbr_len(int n)
{
	int	i;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

unsigned int	nbr_u_len(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}
