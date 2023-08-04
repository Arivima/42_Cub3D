/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:00:00 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/22 19:23:30 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ptr(t_flg *flg, void *ptr, int *n_ch)
{
	int	n_len;
	int	padding;
	int	zero_p;

	if (!ptr && flg->only_dot)
		n_len = 0;
	else
		n_len = nbr_hx_len((unsigned long) ptr);
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - 2 - zero_p;
	if (padding < 0)
		padding = 0;
	if (!flg->minus)
		print_int_padding(n_ch, padding, ' ');
	put_hash('x', n_ch);
	print_int_padding(n_ch, zero_p, '0');
	if (!ptr && !flg->only_dot)
		put_char('0', n_ch);
	if (ptr)
		put_nbr_hx((unsigned long) ptr, 'x', n_ch);
	if (flg->minus)
		print_int_padding(n_ch, padding, ' ');
}
