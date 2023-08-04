/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:57:50 by avilla-m          #+#    #+#             */
/*   Updated: 2021/04/22 19:24:54 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flg
{
	int	hash;
	int	zero;
	int	minus;
	int	space;
	int	plus;
	int	int_sign;
	int	width;
	int	precision;
	int	only_dot;
}				t_flg;

//ft_printf.c
int				ft_printf(const char *in, ...);
void			print_in(const char **in, va_list ap, int *n_ch);
void			set_flg(const char **in, t_flg *flg, va_list ap);
void			init_flg(t_flg *flg);
void			print_arg(const char **in, t_flg flg, va_list ap, int *n_ch);

//ft_flg.c
void			set_zero(t_flg *flg);
void			set_minus(t_flg *flg);
void			set_width(const char **in, t_flg *flg, va_list ap);
void			set_precision(const char **in, t_flg *flg, va_list ap);
void			set_only_dot(t_flg *flg);

//ft_bonus.c
void			set_hash(t_flg *flg);
void			set_space(t_flg *flg);
void			set_plus(t_flg *flg);
void			conv_n(int *ptr, int *n_ch, t_flg flg);

//ft_print_str.c
void			print_str_padding(char *str, t_flg *flg, char to_pr, int *n_ch);
void			print_str_txt(t_flg *flg, char *str, int *n_ch);
void			print_str(t_flg *flg, char *str, int *n_ch);

//ft_print_char_wildcard.c
void			print_char_padding(int c, t_flg *flg, char to_pr, int *n_ch);
void			print_char(t_flg *flg, int c, int *n_ch);
void			print_wildcard(t_flg *flg, int *n_ch);

//ft_print_int.c
void			print_int_padding(int *n_ch, int padding, char to_pr);
void			print_int_sign(t_flg *flg, int *n_ch);
void			set_int_sign(t_flg *flg, int n);
void			print_int(t_flg *flg, int n, int *n_ch);
void			print_int_2(t_flg *flg, int padding, int zero_p, int *n_ch);

//ft_print_unsigned.c
void			print_unsigned(t_flg *flg, unsigned int n, int *n_ch);
void			print_unsigned_2(t_flg *flg, int padding, int *n_ch);
void			put_nbr_u(unsigned int n, int *n_ch);
unsigned int	nbr_u_len(unsigned int n);

//ft_print_ptr.c
void			print_ptr(t_flg *flg, void *ptr, int *n_ch);

//ft_prt_hx.c
void			put_nbr_hx(unsigned long n, const char in, int *n_ch);
void			prt_hx_2(t_flg *flg, const char **in, int padding, int *n_ch);
void			put_hash(const char in, int *n_ch);
int				nbr_hx_len(unsigned long n);
void			prt_hx(t_flg *flg, unsigned int n, const char **in, int *n_ch);

//ft_libft.c
void			ft_putchar_printf(char c, int fd);
void			ft_putstr_printf(char *s, int fd);
void			ft_putnbr_printf(int n, int fd);
size_t			ft_strlen_printf(const char *s);

//utils.c
void			put_char(int c, int *n_ch);
void			put_str(char **str, int *n_ch);
int				nbr_len(int n);
void			put_nbr(int n, int n_len, int *n_ch);

#endif
