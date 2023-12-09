/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:30:44 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 01:25:26 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("0x0 0x1 0x41 0x61 0x7e 0x7f 0x80 0xff " \
	"%d %d %d %d %d %d %d %d %d %d", \
	ft_isascii(0x0), ft_isascii(0x1), ft_isascii(0x41), ft_isascii(0x61), \
	ft_isascii(0x7e), ft_isascii(0x7f), ft_isascii(0x80), ft_isascii(0xff), \
	ft_isascii(0xff000000), ft_isascii(0xff00007f));
	return (0);
} */
