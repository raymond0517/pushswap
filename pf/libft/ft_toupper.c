/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:00:50 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/26 17:25:26 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ((uc >= 'a') && (uc <= 'z'))
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("A Z a z !  \\xff \\xffff %c %c %c %c %c %c %c", \
	(char)ft_toupper('A'), \
	(char)ft_toupper('Z'), \
	(char)ft_toupper('a'), \
	(char)ft_toupper('z'), \
	(char)ft_toupper('!'), \
	(char)ft_toupper(0xff), \
	(char)ft_toupper(0xffff));
	printf("\n");
	return (0);
} */
