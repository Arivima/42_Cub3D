/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:33:31 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/22 19:19:40 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_str(char **str, int *n_ch)
{
	write(1, (*str)++, 1);
	(*n_ch)++;
}

void	put_char(int c, int *n_ch)
{
	write(1, &c, 1);
	(*n_ch)++;
}

void	put_nbr(int n, int n_len, int *n_ch)
{
	ft_putnbr_printf(n, 1);
	(*n_ch) += n_len;
}

void	put_nbr_u(unsigned int n, int *n_ch)
{
	if (n > 9)
		put_nbr_u(n / 10, n_ch);
	ft_putchar_printf(n % 10 + '0', 1);
	(*n_ch)++;
}
