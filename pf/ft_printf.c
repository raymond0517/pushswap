/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:39:33 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 20:14:11 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* if print char by char on the format that is NOT % conversion
	specifier, 
	if it is conversion specifier, it call ft_extract_print_1_conv
		fn to extract and print out the conversion string, in this
		case pcnt will return the number of chars printed by 
		ft_extract_print_1_conv
	ft_extract_print_1_conv returns the number of characters scanned 
		in format, it is stored in skip var,
	with this info, format can be skipped with "skip" number of chars
	if it possible that skip var is 0, because some syntax error in %
		specifier, in this case '%' will not be printed, other chars
		like flags, min, '.', prec value, conv flag will be printed.
	this is extra, not functions of printf, purpose is to ensure to 
		some extend ft_printf will continue working without crashing
		in the case of syntax error in flags, min, precision, and
		conversion character.
	ft_printf will loop through all % conversion in the format string
		there can be more than 1 conversion in format string
	the pcnt accumulates total number of chars printed for all %
		conversions,
	at the end of ft_printf fn, it returns pcnt
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		skip;
	int		pcnt;

	va_start(args, format);
	pcnt = 0;
	while (*format)
	{
		skip = 1;
		if (*format == '%')
		{
			format++;
			skip = (ft_extract_print_1_conv(format, args, &pcnt));
		}
		else
		{
			ft_putchar_fd(*format, 1);
			pcnt++;
		}
		format += skip;
	}
	va_end(args);
	return (pcnt);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[100];
	int		cnt1;
	int		cnt2;

	//strcpy(s, "(%-*.*s)(%08.*i)(%-3c)(%%)(%-20p)(%05d)"
	//"(%013x)(%020u)(%-#22.10X)(%-+14.*d)(%-5c)");
	strcpy(s, "(%-5c)");
	cnt1 = ft_printf(s, '\0');
//	cnt1 = ft_printf(s, 6, 6, NULL, 5, 34, 'x', NULL, 
//	10, 9999, 40, UINT_MAX, 5, 100, '\0');
	ft_printf("\n-----------------\n");
	cnt2 = printf(s, '\0');
//	cnt2 = printf(   s, 6, 6, NULL, 5, 34, 'x', NULL, 
//	10, 9999, 40, UINT_MAX, 5, 100, '\0');
	printf("\nft cnt (%d) \nlx cnt (%d)", cnt1, cnt2);

	return (0);
}*/
