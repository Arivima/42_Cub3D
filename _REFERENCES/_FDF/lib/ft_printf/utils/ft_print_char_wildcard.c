/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_wildcard.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:03:18 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/21 18:03:30 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_padding(int c, t_flg *flg, char to_pr, int *n_ch)
{
	if (--(flg->width) < 0)
		flg->width = 0;
	if (flg->minus)
		put_char(c, n_ch);
	while ((flg->width)--)
		put_char(to_pr, n_ch);
	if (!flg->minus)
		put_char(c, n_ch);
}

void	print_char(t_flg *flg, int c, int *n_ch)
{
	if (flg->zero || flg->precision != -1)
		*n_ch = -1;
	if (flg->width)
		print_char_padding(c, flg, ' ', n_ch);
	else
		put_char(c, n_ch);
}

void	print_wildcard(t_flg *flg, int *n_ch)
{
	if (flg->width)
	{
		if (flg->zero)
			print_char_padding('%', flg, '0', n_ch);
		else
			print_char_padding('%', flg, ' ', n_ch);
	}
	else
		put_char('%', n_ch);
}
