/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_unsigned_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:33:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/15 02:24:44 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	if right-justified, only '0', min width, and precision can apply.
		'0' cannot work with precision.
		hence, '0' min width only.
		or  min width, and precision only.

	************* NOTE *****
	Logic: 
	if '0' flag, no space on left, 
		if min width > unsigned width, 
			print {min - unsigned width} times of '0'
		print unsigned value
	else
		if prec > unsigned length
			add prec to cnt
		else
			add int length to cnt
		if min width > cnt
			print ' ' (min - cnt) times
		if prec > unsigned length
			print '0' (prec - unsigned len) times
		print unsigned
	return tot bytes printed.
		
*/
static int	ft_right_justified_p_int(char *flag, int min, int prec, char *s)
{
	int	cnt;
	int	pcnt;

	cnt = 0;
	cnt += ft_cnt_zero_prefix(prec, s);
	cnt += ft_cnt_numdigits(s);
	pcnt = 0;
	if ((ft_strchr(flag, '0')) && (!(ft_strchr(flag, '.'))))
	{
		if (min > cnt)
			pcnt += ft_pad_char(min - cnt, '0');
		pcnt += ft_pnum(s, 1);
	}
	else
	{
		if (min > cnt)
			pcnt += ft_pad_char(min - cnt, ' ');
		pcnt += ft_pad_char(ft_cnt_zero_prefix(prec, s), '0');
		pcnt += ft_pnum(s, 1);
	}
	return (pcnt);
}

/*
	'+', '#', ' ' flags cannot be applied to unsigned
	'-', '0', min, prec allowed.
	'-' left justified, cannot work with '0'
		work only with min, prec,
		if prec > unsigned digits size, pad left with '0'
	'0' prefix tied to min width , cannot work with prec
	prec longer than unsigned value with prefix '0' to fill prec length
	min length longer than (prec or unsigned value, whichever is longer) will
		pad space left or right (if left justified), 
		however, if '0' flag is used min with no prec and left justfified flag
		then pad space left.
		
*/
int	ft_p_unsigned(char *flag, int min, int prec, char *s)
{
	int		cnt;

	if ((s[0] == '0') && (s[1] == '\0') && (prec == 0))
		s[0] = '\0';
	if (ft_strchr(flag, '-'))
	{
		cnt = ft_zero_prefix(prec, s);
		cnt += ft_pnum(s, 1);
		if (min > cnt)
			cnt += ft_pad_char(min - cnt, ' ');
	}
	else
		cnt = ft_right_justified_p_int(flag, min, prec, s);
	return (cnt);
}
