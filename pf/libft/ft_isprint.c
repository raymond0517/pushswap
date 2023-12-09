/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:13:22 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 01:29:38 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("0x1f 0x20 0x21 0x7d 0x7e 0x7f 0xfe 0xff %d %d %d %d %d %d %d %d", \
	ft_isprint(0x1f), ft_isprint(0x20), ft_isprint(0x21), \
	ft_isprint(0x7d), ft_isprint(0x7e), \
	ft_isprint(0x7f), ft_isprint(0xfe), ft_isprint(0xff));
	printf("\nisprint results\n");
	printf("0x1f 0x20 0x21 0x7d 0x7e 0x7f 0xfe 0xff %d %d %d %d %d %d %d %d", \
	isprint(0x1f), isprint(0x20), isprint(0x21), \
	isprint(0x7d), isprint(0x7e), \
	isprint(0x7f), isprint(0xfe), isprint(0xff));
	return (0);
} */
