/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:31:46 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/08 17:01:36 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (((uc >= 'A') && (uc <= 'Z')) || \
	((uc >= 'a') && (uc <= 'z')) || \
	((uc >= '0') && (uc <= '9')))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("A Z a z 0 9 ~ . 0xff 0xffff %d %d %d %d %d %d %d %d %d %d", \
	ft_isalnum('A'), ft_isalnum('Z'), ft_isalnum('a'), \
	ft_isalnum('z'), ft_isalnum('0'), ft_isalnum('9'), \
	ft_isalnum('~'), ft_isalnum('.'), ft_isalnum(0xff), \
	ft_isalnum(0xffff));
	return (0);
} */
