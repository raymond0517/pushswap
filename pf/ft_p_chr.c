/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_chr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:46:32 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/15 01:50:13 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pchr(char *s)
{
	ft_putchar_fd(s[0], 1);
	return (1);
}

/*
	if right-justified, only min width

	Logic: 
		if min width > cnt
			print ' ' (min - cnt) times
		if '#', print '0x/0X'
		print int len
	return tot bytes printed.
		
*/

static int	ft_right_justified_p_ptr(int min, char *s)
{
	int	cnt;
	int	pcnt;

	cnt = 1;
	pcnt = 0;
	if (min > cnt)
		pcnt += ft_pad_char(min - cnt, ' ');
	pcnt += ft_pchr(s);
	return (pcnt);
}

/*
	only '-' flag and min width length allowed
	expect int input, however converted to s string, s[0] holds the char
	if input char is 0, return ""
*/
int	ft_p_chr(char *flag, int min, char *s)
{
	int		cnt;

	if (ft_strchr(flag, '-'))
	{
		cnt = ft_pchr(s);
		if (min > cnt)
			cnt += ft_pad_char(min - cnt, ' ');
	}
	else
		cnt = ft_right_justified_p_ptr(min, s);
	return (cnt);
}
