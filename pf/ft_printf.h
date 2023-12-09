/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:36:56 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 14:28:23 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_p_int(char *flag, int min, int prec, char *s);
int		ft_p_hex(char *flag, int min, int prec, char *s);
int		ft_p_unsigned(char *flag, int min, int prec, char *s);
int		ft_p_ptr(char *flag, int min, char *s);
int		ft_p_chr(char *flag, int min, char *s);
int		ft_p_str(char *flag, int min, int prec, char *s);
char	*ft_utoa(unsigned int n);
void	ft_hexint(unsigned long in, char *r, int i, int upcase);
void	ft_reverse(char *s);
char	ft_min_prec_conv(int *i, int *min, int *prec, char const *f);
int		ft_extract_print_1_conv(char const *f, va_list args, int *pcnt);
int		ft_p_conv_s_x_upp_x(char *flag, int min, int prec, va_list args);
int		ft_p_conv_percent_c_p(char *flag, int min, va_list args);
int		ft_p_conv_i_d_u(char *flag, int min, int prec, va_list args);
int		ft_pnum(char *s, int nosign);
int		ft_pad_char(int c, char ch);
int		ft_cnt_numdigits(char *s);
int		ft_cnt_zero_prefix(int prec, char *s);
int		ft_zero_prefix(int prec, char *s);

#endif
