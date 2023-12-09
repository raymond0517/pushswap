/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_hex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:33:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/15 02:22:53 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p_0x(char *flag)
{
	if (ft_strchr(flag, '#'))
	{
		if (ft_strchr(flag, 'x'))
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		return (2);
	}
	return (0);
}

/*
	if right-justified, only '0' '#' and min width, and precision can apply.
		'0' cannot work with precision.
		hence, '0', '#', min width only.
		or '#' min width, and precision only.

	************* NOTE *****
	argument flag has appended with x or X conv char, 
	due to 42's max 4 arguments limit
	Logic: 
	if '0' flag, no space on left, 
		if '#' flag, print 0x or 0X, 
		if min width > int width + 0x/0X , 
			print {min - (int width + 2 (if '#'))} times of '0'
		print int hex
	else
		if '#' flag, cnt 0x / 0X 2 bytes;
		if prec > int length
			add prec to cnt
		else
			add int length to cnt
		if min width > cnt
			print ' ' (min - cnt) times
		if '#', print '0x/0X'
		if prec > int length
			print '0' (prec - int len) times
		print int len
	return tot bytes printed.
		
*/
int	ft_right_justified_p_hex(char *flag, int min, int prec, char *s)
{
	int	cnt;
	int	pcnt;

	cnt = 0;
	if (ft_strchr(flag, '#'))
		cnt += 2;
	cnt += ft_cnt_zero_prefix(prec, s);
	cnt += ft_cnt_numdigits(s);
	pcnt = 0;
	if ((ft_strchr(flag, '0')) && (!ft_strchr(flag, '.')))
	{
		pcnt += ft_p_0x(flag);
		if (min > cnt)
			pcnt += ft_pad_char(min - cnt, '0');
		pcnt += ft_pnum(s, 1);
	}
	else
	{
		if (min > cnt)
			pcnt += ft_pad_char(min - cnt, ' ');
		pcnt += ft_p_0x(flag);
		pcnt += ft_pad_char(ft_cnt_zero_prefix(prec, s), '0');
		pcnt += ft_pnum(s, 1);
	}
	return (pcnt);
}

static void	ft_remove_hex_flag(char *flag)
{
	int	i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] != '#')
			i++;
		else
		{
			i++;
			while (flag[i])
			{
				flag[i - 1] = flag[i];
				i++;
			}
			flag[i - 1] = flag[i];
		}
	}
}

/*
	Xx test with #, '-', '0' flags, flags ' ', '+' cannot use
	  can have min width and precision
	 0 and '-' not together, 0 also cannot work with . (prec)
	 so 0 only with # , min width
	 left justified can have precision
	 ' ' and '+' not allowed for xX whether '-' left justified or not
	 # simple adds '0x', or '0X' as prefix to start of display hex
	   it works with left or right justified, min width with precision
	   precision of 0 for hex value 0 will be "" null string
	   it takes unsigned int, no negative value
	if right-justified, only '0' '#' and min width, and precision can apply.
		'0' cannot work with precision.
		hence, '0', '#', min width only.
		or '#' min width, and precision only.

	if hex value is 0, don't print 0x or 0X even '#' exists
		if prec == 0 and hex value == 0, then print "" for hex value
	if left justified, work only with '-', '#', 
	   min, and precision.
	   if # "0x" or "0X" prefix, it is counted as part of min width
	     so examine precision, if precision more than number of digits
		 the int has, pad left with '0'

	argument flag has appended with x or X conv char, 
	due to 42's max 4 arguments limit
*/
int	ft_p_hex(char *flag, int min, int prec, char *s)
{
	int		cnt;

	if ((s[0] == '0') && (s[1] == '\0'))
	{
		ft_remove_hex_flag(flag);
		if (prec == 0)
			s[0] = '\0';
	}
	if (ft_strchr(flag, '-'))
	{
		cnt = ft_p_0x(flag);
		cnt += ft_zero_prefix(prec, s);
		cnt += ft_pnum(s, 1);
		if (min > cnt)
			cnt += ft_pad_char(min - cnt, ' ');
	}
	else
		cnt = ft_right_justified_p_hex(flag, min, prec, s);
	return (cnt);
}
