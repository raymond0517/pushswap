/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 00:33:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 00:20:58 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* print truncated string if len is shorter then string len */
static int	ft_pstr(char *s, int len)
{
	int	i;

	i = 0;
	while ((s[i]) && (i < len))
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_get_p_len(int prec, char *s)
{
	int	i;

	i = 0;
	while ((s[i]) && (i < prec))
		i++;
	return (i);
}

static int	ft_right_justified_p_str(int min, char *s, int len)
{
	int	pcnt;

	pcnt = 0;
	if (min > len)
		pcnt += ft_pad_char(min - len, ' ');
	pcnt += ft_pstr(s, len);
	return (pcnt);
}

/*
	only '-' min, prec allowed
	flags '+' ' ' '#' '0' not allowed
	prec value if shorter than string, will truncate string
	    if longer than string, will not pad space left or right
	prec with only a '.' will default to 0, hence, truncate all string
		leaving only the minimum width of empty spaces.
	if input string is empty will just display spaces of min width
	input string cannot be NULL	
	printf("\n(%20.10s)", NULL);
*/
int	ft_p_str(char *flag, int min, int prec, char *s)
{
	int		cnt;
	int		len;

	len = ft_get_p_len(prec, s);
	if (ft_strchr(flag, '-'))
	{
		cnt = ft_pstr(s, len);
		if (min > cnt)
			cnt += ft_pad_char(min - cnt, ' ');
	}
	else
		cnt = ft_right_justified_p_str(min, s, len);
	return (cnt);
}
