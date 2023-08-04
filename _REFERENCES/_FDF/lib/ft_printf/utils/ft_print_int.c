/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:33:40 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/21 17:50:10 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_padding(int *n_ch, int padding, char to_pr)
{
	while (padding--)
		put_char(to_pr, n_ch);
}

void	print_int_sign(t_flg *flg, int *n_ch)
{
	if (flg->int_sign)
		put_char('-', n_ch);
	else if (flg->plus)
		put_char('+', n_ch);
	else if (flg->space)
		put_char(' ', n_ch);
}

void	set_int_sign(t_flg *flg, int n)
{
	flg->int_sign = n < 0;
}

void	print_int(t_flg *flg, int n, int *n_ch)
{
	int		n_len;
	int		padding;
	int		zero_p;

	set_int_sign(flg, n);
	n_len = nbr_len(n);
	if (n < 0)
		n *= -1;
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p
		-(flg->int_sign || flg->plus || flg->space);
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	print_int_2(flg, padding, zero_p, n_ch);
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr(n, nbr_len(n), n_ch);
	if (flg->minus)
		print_int_padding(n_ch, padding, ' ');
}

void	print_int_2(t_flg *flg, int padding, int zero_p, int *n_ch)
{
	if (!flg->minus)
	{
		if (!(flg->precision == -1 && flg->zero))
			print_int_padding(n_ch, padding, ' ');
		print_int_sign(flg, n_ch);
		if (flg->precision == -1 && flg->zero)
			print_int_padding(n_ch, padding, '0');
	}
	else
		print_int_sign(flg, n_ch);
	print_int_padding(n_ch, zero_p, '0');
}
