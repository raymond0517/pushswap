/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_common_fn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:12:52 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/12 16:35:22 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* if nosign flag is 1, then will not print out the '-' sign */
int	ft_pnum(char *s, int nosign)
{
	int	i;

	i = 0;
	if ((nosign) && (s[0] == '-'))
		s++;
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

/* print ch number of times, using c */
int	ft_pad_char(int c, char ch)
{
	int	r;

	r = c;
	while (c != 0)
	{
		ft_putchar_fd(ch, 1);
		c--;
	}
	return (r);
}

/* return number of digits pointed in s, ignore '-' sign */
int	ft_cnt_numdigits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '-')
		i--;
	return (i);
}

/* prec defines minimum number of digits in s,
	if s has less digits then prec, will return
	the number of '0' to be padded to the left
	in order to have 'prec' number of total printed digits
*/
int	ft_cnt_zero_prefix(int prec, char *s)
{
	int	l;

	l = ft_cnt_numdigits(s);
	if (prec > l)
		return (prec - l);
	else
		return (0);
}

/* prec defines minimum number of digits in s,
	if s has less digits then prec, print
	the number of '0' to be padded to the left
	in order to have 'prec' number of total printed digits
*/
int	ft_zero_prefix(int prec, char *s)
{
	int	l;
	int	cnt;

	l = ft_strlen(s);
	if (s[0] == '-')
		l--;
	if (prec > l)
	{
		cnt = prec - l;
		l = 0;
		while (l < cnt)
		{
			ft_putchar_fd('0', 1);
			l++;
		}
	}
	else
		return (0);
	return (l);
}
