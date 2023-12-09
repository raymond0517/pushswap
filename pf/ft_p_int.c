/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:33:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 18:33:54 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -16.18i will make total digits 18 prefix with 0, if i is 10 or less
	 16 is the minimum including -ve sign, so if min is 20, then
	-ve sign plus 18 precision length, still need 1 space)
	min refer to minimum display width, including -ve sign and padding spaces
		or padding prefix zeroes if actual is longer, no truncate
	prec refers to minimum number of digits to display, if actual is longer
		, no truncate.
	if - (justify left) exists, extra space will pad to the right
	else pad to the left.
	precision refers to number of digits displayed exclude -ve sign
	presence of '.' indicates presence of precision.
	prec == -2 indicate absence of '.', no precision.
	default precision is 1 for d, o, u, x, X. 
	if precision is 0, 0 integer it returns NULL string.
	0 flag ignored with precision and i/d conversion
	0 flag ignored with '-' left justified flag.
	0 flag fill the right justified integer with 0 padded to left to fill
		the entire min width.
	so +20.19d the same output as +020d
	%20.19d not the same as %020d because of less 1 prefix 0 for %20.19d
	%20.20d same as %020d
	if int length is longer than min length, then min length is ignored
	else min length is longer than int length, space (if 0 flag not exist)
	is padded to left or right (if - flag exists)
	if ' ' flag and int is +ve, then a space is guaranteed instead of a '+' 
	sign byte before left more digit.
	' ' ignored when '+' exists, in general ' ' and '+' should not exists 
	the same time for int value; ' ' is treated as a +ve signed byte.
	without ' ' or '+' flag, +ve sign byte will be dropped.
	precision is applied when int length is smaller than precision
	0 prefix applied to fill the precision length, precision length doesn't
	include the sign byte either + ' ' or -
	if precision length is longer than min length, and precision length is
	longer than int length, then, prefix zero will prefill entire prec length
	display length for int value will be precision length, if min length is 
	shorter. if precision length is shorter than int length, it will be ignored
	- flag not exists will default to right justified.

	default min width is 0
	if left justified, '0' flag doesn't applied, 
		+ flag ' ' flag print '+/ ' byte if not -ve int
		if -ve number print '-'
		then if precision exists, longer than len of number, prefix 0 to 
			prec len
		then print number
		then print remaining space if min width longer than total printed

	if right justified
		if '0' flag , if -ve num will have '-' then '0's then number
				if +ve and no ' ' flag then all '0' to the left then number
				if +ve and '+/ ' flag then '+/ ' then all '0', then number
			no precision allowed when '0' flag
		no '0' flag, same logic as above except ' ' is padded to left
				'-+ ' sign byte will not appear as 1st byte instead after all 
				repeated ' ' and before print number, ' ' is padded provided
				min width > int length
			(prec when . with no prec value default to be 0,
			 meaning int value 0 will return ""
			 prec .0 will also return "" when int value is 0, 
			 if without . prec default to be 1)

*/

static int	ft_cnt_sign_byte(char *flag, char *s)
{
	if ((s[0] == '-') || (ft_strchr(flag, ' ')) || (ft_strchr(flag, '+')))
		return (1);
	else
		return (0);
}

static int	ft_p_sign_byte(char *flag, char *s)
{
	if (s[0] == '-')
		ft_putchar_fd('-', 1);
	else if (ft_strchr(flag, ' '))
		ft_putchar_fd(' ', 1);
	else if (ft_strchr(flag, '+'))
		ft_putchar_fd('+', 1);
	else
		return (0);
	return (1);
}

/* if '0' flag, fill 0 to the full min width length incl sign byte
	0 flag don't work with precision, only '+', ' ', and right justified
 	if no '0' flag, will act on '+', ' ', min, prec only for right justified.
 	cnt sign byte + zero prefix for precision + numdigits
	 if min width > than the sum, print extra spaces to the left
*/
int	ft_right_justified_p_int(char *flag, int min, int prec, char *s)
{
	int	cnt;
	int	pcnt;

	cnt = ft_cnt_sign_byte(flag, s);
	cnt += ft_cnt_zero_prefix(prec, s);
	cnt += ft_cnt_numdigits(s);
	pcnt = 0;
	if ((ft_strchr(flag, '0')) && (!ft_strchr(flag, '.')))
	{
		pcnt += ft_p_sign_byte(flag, s);
		if (min > cnt)
			pcnt += ft_pad_char(min - cnt, '0');
		pcnt += ft_pnum(s, 1);
	}
	else
	{
		if (min > cnt)
			pcnt += ft_pad_char(min - cnt, ' ');
		pcnt += ft_p_sign_byte(flag, s);
		pcnt += ft_pad_char(ft_cnt_zero_prefix(prec, s), '0');
		pcnt += ft_pnum(s, 1);
	}
	return (pcnt);
}

/* if left justified, examine prec, if prec more than int digit size, pad 
	right with '0' */
int	ft_p_int(char *flag, int min, int prec, char *s)
{
	int		cnt;

	if ((prec == 0) && (s[0] == '0') && (s[1] == '\0'))
		s[0] = '\0';
	if (ft_strchr(flag, '-'))
	{
		cnt = ft_p_sign_byte(flag, s);
		cnt += ft_zero_prefix(prec, s);
		cnt += ft_pnum(s, 1);
		if (min > cnt)
			cnt += ft_pad_char(min - cnt, ' ');
	}
	else
		cnt = ft_right_justified_p_int(flag, min, prec, s);
	return (cnt);
}
