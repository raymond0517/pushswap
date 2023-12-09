/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:33:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/15 02:23:36 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p_ptr_0x(char *s)
{
	if (s[0] == '(')
		return (0);
	ft_putstr_fd("0x", 1);
	return (2);
}

/*
	if right-justified, only min width

	Logic: 
		if min width > cnt
			print ' ' (min - cnt) times
		print int len
	return tot bytes printed.
	*s can contains "(nil)" when pointer is null
	so '0x' should not be printed in this case
*/
static int	ft_right_justified_p_ptr(int min, char *s)
{
	int	cnt;
	int	pcnt;

	if (s[0] != '(')
		cnt = 2;
	else
		cnt = 0;
	cnt += ft_cnt_numdigits(s);
	pcnt = 0;
	if (min > cnt)
		pcnt += ft_pad_char(min - cnt, ' ');
	pcnt += ft_p_ptr_0x(s);
	pcnt += ft_pnum(s, 1);
	return (pcnt);
}

/*
	only '-' flag and min width length allowed
	hex is displayed lowercase
*/
int	ft_p_ptr(char *flag, int min, char *s)
{
	int		cnt;

	if ((s[0] == '0') && (s[1] == '\0'))
		ft_strlcpy(s, "(nil)", 6);
	if (ft_strchr(flag, '-'))
	{
		cnt = ft_p_ptr_0x(s);
		cnt += ft_pnum(s, 1);
		if (min > cnt)
			cnt += ft_pad_char(min - cnt, ' ');
	}
	else
		cnt = ft_right_justified_p_ptr(min, s);
	return (cnt);
}
