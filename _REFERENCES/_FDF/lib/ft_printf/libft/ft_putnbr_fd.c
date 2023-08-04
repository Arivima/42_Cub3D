/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:55:55 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/12 16:34:40 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, int fd)
{
	long int		long_n;

	if (n < 0)
		long_n = -(long int)n;
	else
		long_n = n;
	if (long_n > 9)
	{
		ft_putnbr_printf(long_n / 10, fd);
		ft_putchar_printf((long_n % 10) + '0', fd);
	}
	else
		ft_putchar_printf(long_n + '0', fd);
}
