/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:25:16 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/22 18:50:14 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(const char **in, t_flg flg, va_list ap, int *n_ch)
{
	if (**in == 'c')
		print_char(&flg, va_arg(ap, int), n_ch);
	else if (**in == 's')
		print_str(&flg, va_arg(ap, char *), n_ch);
	else if (**in == 'p')
		print_ptr(&flg, va_arg(ap, void *), n_ch);
	else if (**in == 'd' || **in == 'i')
		print_int(&flg, va_arg(ap, int), n_ch);
	else if (**in == 'u')
		print_unsigned(&flg, va_arg(ap, unsigned int), n_ch);
	else if (**in == 'x' || **in == 'X')
		prt_hx(&flg, va_arg(ap, unsigned int), in, n_ch);
	else if (**in == '%')
		print_wildcard(&flg, n_ch);
	else if ((**in) == 'n')
		conv_n(va_arg(ap, int *), n_ch, flg);
	else
		*n_ch = -1;
	(*in)++;
}

void	init_flg(t_flg *flg)
{
	flg->hash = 0;
	flg->zero = 0;
	flg->minus = 0;
	flg->space = 0;
	flg->plus = 0;
	flg->int_sign = 0;
	flg->width = 0;
	flg->precision = -1;
	flg->only_dot = 0;
}

void	set_flg(const char **in, t_flg *flg, va_list ap)
{
	init_flg(flg);
	if (**in == '#')
	{
		(*in)++;
		set_hash(flg);
	}
	while (**in == '0' || **in == ' '
		|| **in == '+' || **in == '-' )
	{
		if (**in == '0')
			set_zero(flg);
		if (**in == '-')
			set_minus(flg);
		if (**in == ' ')
			set_space(flg);
		if (**in == '+')
			set_plus(flg);
		(*in)++;
	}
	if (**in == '*' || (**in > '0' && **in <= '9'))
		set_width(in, flg, ap);
	if (**in == '.')
		set_precision(in, flg, ap);
}

void	print_in(const char **in, va_list ap, int *n_ch)
{
	t_flg	flg;

	while (**in)
	{
		if (**in == '%')
		{
			(*in)++;
			set_flg(in, &flg, ap);
			print_arg(in, flg, ap, n_ch);
			if (*n_ch == -1)
				return ;
		}
		else
			put_str((char **)in, n_ch);
	}
}

int	ft_printf(const char *in, ...)
{
	va_list	ap;
	int		n_ch;

	if (!in)
		return (-1);
	n_ch = 0;
	va_start(ap, in);
	print_in(&in, ap, &n_ch);
	va_end(ap);
	return (n_ch);
}
