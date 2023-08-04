/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:32:59 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/21 20:12:42 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(t_flg *flg, unsigned int n, int *n_ch)
{
	int		n_len;
	int		padding;
	int		zero_p;

	if (flg->minus && flg->zero)
	{
		*n_ch = -1;
		return ;
	}
	n_len = nbr_u_len(n);
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p;
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	print_unsigned_2(flg, padding, n_ch);
	print_int_padding(n_ch, zero_p, '0');
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr_u(n, n_ch);
	if (flg->minus)
		print_int_padding(n_ch, padding, ' ');
}

void	print_unsigned_2(t_flg *flg, int padding, int *n_ch)
{
	if (!flg->minus)
	{
		if (!(flg->precision == -1 && flg->zero))
			print_int_padding(n_ch, padding, ' ');
		else
			print_int_padding(n_ch, padding, '0');
	}
}
