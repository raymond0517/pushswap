/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:28:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/08 16:31:57 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ((uc >= 'A') && (uc <= 'Z'))
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("A Z a z ! 0x0 0xff 0xffff %c %c %c %c %c %d %d %d", \
	ft_tolower('A'), ft_tolower('Z'), ft_tolower('a'), \
	ft_tolower('z'), ft_tolower('!'), ft_tolower(0x0), \
	ft_tolower(0xff), ft_tolower(0xffff));
	printf("\n");
	return (0); 
} */
