/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:25:03 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/22 15:19:16 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_hx(t_flg *flg, unsigned int n, const char **in, int *n_ch)
{
	int	n_len;
	int	padding;
	int	zero_p;

	n_len = nbr_hx_len((unsigned long) n);
	zero_p = flg->precision - n_len;
	if (zero_p < 0)
		zero_p = 0;
	padding = flg->width - n_len - zero_p;
	if (padding < 0)
		padding = 0;
	if (n == 0 && flg->only_dot == 1)
		padding = flg->width;
	prt_hx_2(flg, in, padding, n_ch);
	print_int_padding(n_ch, zero_p, '0');
	if (!(n == 0 && flg->only_dot == 1))
		put_nbr_hx((unsigned long) n, **in, n_ch);
	if (n == 0 && !flg->only_dot)
		put_char('0', n_ch);
	if (flg->minus)
		print_int_padding(n_ch, padding, ' ');
}

void	prt_hx_2(t_flg *flg, const char **in, int padding, int *n_ch)
{
	if (!flg->minus && !(flg->precision == -1 && flg->zero))
		print_int_padding(n_ch, padding, ' ');
	if (flg->hash)
		put_hash(**in, n_ch);
	if (!flg->minus && (flg->precision == -1 && flg->zero))
		print_int_padding(n_ch, padding, '0');
}

void	put_hash(const char in, int *n_ch)
{
	put_char('0', n_ch);
	if (in == 'x')
		put_char('x', n_ch);
	else
		put_char('X', n_ch);
}

void	put_nbr_hx(unsigned long n, const char in, int *n_ch)
{
	char	n_hx;

	if (n)
	{
		n_hx = "0123456789abcdef" [n % 16];
		if (n_hx >= 'a' && n_hx <= 'f' && in == 'X')
			n_hx -= 32;
		put_nbr_hx((unsigned long) n / 16, in, n_ch);
		put_char(n_hx, n_ch);
	}
}

int	nbr_hx_len(unsigned long n)
{
	int	n_len;

	n_len = 1;
	while (n >= 16)
	{
		n /= 16;
		n_len++;
	}
	return (n_len);
}
